/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:34:15 by mbentale          #+#    #+#             */
/*   Updated: 2024/12/28 18:03:14 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	total_width(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	close(fd);
	return (ft_strlen(line) - 1);
}

int	total_height(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
	}
	close(fd);
	return (count);
}

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

