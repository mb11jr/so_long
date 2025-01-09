/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/09 13:02:41 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	total_collectibles(t_vars *vars)
{
	int x;
	int y;
	int count;

	count = 0;
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
	char	*line;
	int		rows;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		map_error("The map file doesn't exist!");
	rows = 0;
	while ((line = get_next_line(fd)))
	{
		if (rows == 0)
			vars->win_width = TILE_SIZE * ft_linelen(line);
		rows++;
	}
	vars->win_height = TILE_SIZE * rows;
	if (!vars->win_height || !vars->win_width)
		map_error("The map file is empty!");
	vars->map = malloc((rows + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	rows = 0;
	while ((line = get_next_line(fd)) != NULL)
		vars->map[rows++] = ft_substr(line, 0, ft_linelen(line));
	vars->map[rows] = NULL;
	close(fd);
}
