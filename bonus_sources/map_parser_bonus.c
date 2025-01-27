/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:11:32 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/27 11:50:50 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_vars *vars, char **map, int x, int y)
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
	if (map[y][x] == 'E' || map[y][x] == 'N')
	{
		if (map[y][x] == 'E')
			vars->reachable_exit++;
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'V';
	flood_fill(vars, map, x + 1, y);
	flood_fill(vars, map, x - 1, y);
	flood_fill(vars, map, x, y + 1);
	flood_fill(vars, map, x, y - 1);
}

static char	**clone_map(char **original, int height, int width)
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

static int	check_path(t_vars *vars)
{
	char	**map;

	map = clone_map(vars->map, vars->win_height / TILE_SIZE, vars->win_width
			/ TILE_SIZE);
	flood_fill(vars, map, vars->pos.x / TILE_SIZE, vars->pos.y / TILE_SIZE);
	free_map(map, vars->win_height / TILE_SIZE);
	if (vars->reachable_collectibles == vars->total_collectibles
		&& vars->reachable_exit == 1)
		return (1);
	return (0);
}

void	map_parser(t_vars *vars)
{
	if (!validate_map(vars))
		free_and_exit(vars, 3,
			"The map is invalid! There are unrecognizable characters.");
	if (!is_rectangular(vars))
		free_and_exit(vars, 3, "The map is not rectangular!");
	if (!enclosed_in_walls(vars))
		free_and_exit(vars, 3, "The map is not enclosed in walls!");
	if (!check_exit_start(vars))
		free_and_exit(vars, 3,
			"The map must contain exactly one player and one exit!");
	if (vars->total_collectibles < 1)
		free_and_exit(vars, 3, "The map must have at least one collectible!");
	if (!check_path(vars))
		free_and_exit(vars, 3,
			"No valid path in the map: the player can't reach the exit.");
	if (vars->win_width > 1920)
		free_and_exit(vars, 3, "The map exceeds the maximum window width!");
	if (vars->win_height > 1080)
		free_and_exit(vars, 3, "The map exceeds the maximum window height!");
}
