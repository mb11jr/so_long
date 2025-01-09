/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:11:32 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/09 13:08:09 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(0);
}

int	is_rectangular(t_vars *vars)
{
	int	i;
	int	len;

	len = ft_linelen(vars->map[0]);
	i = 1;
	while (vars->map[i])
	{
		if (ft_linelen(vars->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	enclosed_in_walls(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[0][j] && vars->map[vars->win_height / TILE_SIZE - 1][j])
	{
		if (vars->map[0][j] != '1' || vars->map[vars->win_height / TILE_SIZE
			- 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (vars->map[i] && i != vars->win_height / TILE_SIZE - 1)
	{
		if (vars->map[i][0] != '1' || vars->map[i][ft_linelen(vars->map[i])
			- 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_exit_start(t_vars *vars)
{
	int	i;
	int	j;
	int	count_exit;
	int	count_player;

	count_exit = 0;
	count_player = 0;
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'E')
				count_exit++;
			if (vars->map[i][j] == 'P')
				count_player++;
			if (count_exit > 1 || count_player > 1)
				return (0);
		}
	}
	if (count_exit == 0 || count_player == 0)
		return (0);
	return (1);
}

int	count_collectibles(t_vars *vars)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	valid_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] != '1' && vars->map[i][j] != 'C'
				&& vars->map[i][j] != 'E' && vars->map[i][j] != '0'
				&& vars->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_name(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] == 'r' && s[i - 1] == 'e' && s[i - 2] == 'b' && s[i - 3] == '.')
		return (1);
	return (0);
}
void	flood_fill(t_vars *vars, char **map, int x, int y)
{
	int	height;
	int	width;

	height = vars->win_height / TILE_SIZE;
	width = vars->win_width / TILE_SIZE;
	if (x < 0 || y < 0 || x >= width || y >= height || map[y][x] == '1'
		|| map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		vars->reachable_collectibles++;
	else if (map[y][x] == 'E')
		vars->reachable_exit++;
	map[y][x] = 'V';
	flood_fill(vars, map, x + 1, y);
	flood_fill(vars, map, x - 1, y);
	flood_fill(vars, map, x, y + 1);
	flood_fill(vars, map, x, y - 1);
}

char	**clone_map(char **original, int height, int width)
{
	char	**clone;
	int		i;

	clone = malloc(height * sizeof(char *));
	if (!clone)
		return (NULL);
	i = 0;
	while (i < height)
	{
		clone[i] = malloc((width + 1) * sizeof(char));
		if (!clone[i])
		{
			while (--i >= 0)
				free(clone[i]);
			free(clone);
			return (NULL);
		}
		ft_strlcpy(clone[i], original[i], width + 1);
		i++;
	}
	return (clone);
}
void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_path(t_vars *vars)
{
	char	**map;

	map = clone_map(vars->map, vars->win_height / TILE_SIZE, vars->win_width
			/ TILE_SIZE);
	flood_fill(vars, map, vars->player->x / TILE_SIZE, vars->player->y
		/ TILE_SIZE);
	free_map(map, vars->win_height / TILE_SIZE);
	if (vars->reachable_collectibles == vars->total_collectibles
		&& vars->reachable_exit == 1)
		return (1);
	return (0);
}

void	map_parser(t_vars *vars)
{
	if (!valid_map(vars))
		map_error("The map is invalid! There are unrecognizable characters.");
	if (!is_rectangular(vars))
		map_error("The map is not rectangular!");
	if (!enclosed_in_walls(vars))
		map_error("The map is not enclosed in walls!");
	if (!check_exit_start(vars))
		map_error("The map doesn't contain exactly one player and one exit!");
	if (count_collectibles(vars) < 1)
		map_error("The map must have at least one collectible!");
	if (!check_path(vars))
		map_error("There is no valid path in the map!\n(The player can't reach the exit after collecting all the collectibles)");
}
