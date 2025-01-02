/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/02 21:09:13 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_width(t_vars *vars)
{
	int		fd;
	char	*line;

	fd = open(vars->map->path, O_RDONLY);
	line = get_next_line(fd);
	close(fd);
	return (ft_strlen(line) - 1);
}

int	map_height(t_vars *vars)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(vars->map->path, O_RDONLY);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
	}
	close(fd);
	return (count);
}

void	read_map(t_vars *vars)
{
    int		fd;
	char	*line;
	int		rows;

	fd = open(vars->map->path, O_RDONLY);
	 //add an error message
	rows = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		rows++;
		free(line);
	}
	vars->map->content = malloc((rows + 1) * sizeof(char *));
	fd = open(vars->map->path, O_RDONLY);
	rows = 0;
	while ((line = get_next_line(fd)) != NULL)
		vars->map->content[rows++] = line;
	vars->map->content[rows] = NULL;
	close(fd);
}
