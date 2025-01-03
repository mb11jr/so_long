/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/03 10:51:28 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_vars *vars, char *path)
{
    int		fd;
	char	*line;
	int		rows;

	fd = open(path, O_RDONLY);
	 //add an error message
	rows = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (rows == 0)
			vars->win_width = TILE_SIZE * (ft_strlen(line) - 1);
		rows++;
		free(line);
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
