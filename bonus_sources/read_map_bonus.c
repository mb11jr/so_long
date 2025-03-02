/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/28 12:43:46 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *s)
{
	ft_printf("\033[1;31mError!\n\033[0m");
	ft_printf("\033[1m%s\n\033[0m", s);
	exit(12);
}

static int	map_height(t_vars *vars, int fd)
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
		free_and_exit(vars, 3, "The map file is empty!");
	return (rows);
}

void	read_map(t_vars *vars, char *path)
{
	int		fd;
	char	*line;
	int		rows;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		free_and_exit(vars, 2, "The map file doesn't exist!");
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

int	ft_linelen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
