/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/11 15:05:27 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(t_vars *vars, int fd)
{
	char	*line;
	int		rows;

	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (rows == 0)
			vars->win_width = TILE_SIZE * ft_linelen(line);
		rows++;
		line = get_next_line(fd);
	}
	vars->win_height = TILE_SIZE * rows;
	if (!vars->win_height || !vars->win_width)
		ft_error("The map file is empty!");
	return (rows);
}

void	read_map(t_vars *vars, char *path)
{
	int		fd;
	char	*line;
	int		rows;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("The map file doesn't exist!");
	rows = map_height(vars, fd);
	vars->map = malloc((rows + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		vars->map[rows++] = ft_substr(line, 0, ft_linelen(line));
		line = get_next_line(fd);
	}
	vars->map[rows] = NULL;
	close(fd);
}
