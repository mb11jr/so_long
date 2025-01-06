/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/05 13:33:28 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(0);
}

void	total_collectibles(t_vars *vars, char *path)
{
	int x;
	int y;
	int count;

	count = 0;
	read_map(vars, path);
	y = 0;
	while(vars->map[y])
	{
		x = 0;
		while(vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				vars->total_collectibles = ++count;
			x++;	
		}
	y++;	
	}
}
void	map_parser(t_vars *vars, char *path)
{
	int i;
	size_t len;

	read_map(vars, path);
	len = ft_strlen(vars->map[0]);
	i = 1;
	while (vars->map[i])
	{
		if (ft_strlen(vars->map[i]) != len)
		{
			ft_printf("The map is not rectangular!");
			exit(0);
		}
		i++;
	}
}

int	ft_linelen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
void	read_map(t_vars *vars, char *path)
{
    int		fd;
	// size_t len;
	char	*line;
	int		rows;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		map_error("The map file doesn't exist!");
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (rows == 0)
			vars->win_width = TILE_SIZE * ft_linelen(line);
		if (ft_linelen(line) != vars->win_width / TILE_SIZE)
			map_error("The map is not rectangular!");
		rows++;
		line = get_next_line(fd);
	}
	vars->win_height = TILE_SIZE * rows;
	vars->map = malloc((rows + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	rows = 0;
	while ((line = get_next_line(fd)) != NULL)
		vars->map[rows++] = line;
	vars->map[rows] = NULL;
	close(fd);
}
