/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2024/12/28 12:37:39 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **read_map(const char *filename)
{
    int		fd;
	char	**map;
	char	*line;
	int		rows;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL); //add an error messager
	rows = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		rows++;
		free(line);
	}
	map = malloc((rows + 1) * sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	fd = open(filename, O_RDONLY);
	rows = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[rows++] = line;
	}
	map[rows] = NULL;
	close(fd);
	return (map);
}

