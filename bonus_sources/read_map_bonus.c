/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/24 22:52:08 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(t_vars *vars, char *s)
{
	ft_printf("Error!\n");
	ft_printf("%s\n", s);
	ft_free(vars, 3);
}

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
		free(line);
		line = get_next_line(fd);
	}
	vars->win_height = TILE_SIZE * rows;
	if (!vars->win_height || !vars->win_width)
		error_msg(vars, "The map file is empty!");
	return (rows);
}

void	read_map(t_vars *vars, char *path)
{
	int		fd;
	char	*line;
	int		rows;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(vars, "The map file doesn't exist!");
	rows = map_height(vars, fd);
	vars->map = malloc((rows + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		vars->map[rows++] = ft_substr(line, 0, ft_linelen(line));
		free(line);
		line = get_next_line(fd);
	}
	vars->map[rows] = NULL;
	close(fd);
}
