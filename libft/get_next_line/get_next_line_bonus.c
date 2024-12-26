/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:27:44 by mbentale          #+#    #+#             */
/*   Updated: 2024/11/30 10:07:13 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*add_to_stash(char *stash_buffer, char *read_buffer)
{
	char	*result;

	result = ft_strjoin(stash_buffer, read_buffer);
	free(stash_buffer);
	return (result);
}

static char	*read_from_file(char *stash_buffer, int fd)
{
	char		*read_buffer;
	ssize_t		bytes_read;

	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			free(stash_buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		read_buffer[bytes_read] = '\0';
		stash_buffer = add_to_stash(stash_buffer, read_buffer);
		if (ft_strchr(stash_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (stash_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash_buffer[FD_OPEN_MAX];
	int			i;
	char		*rest;

	if (fd < 0 || fd >= FD_OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash_buffer[fd] = read_from_file(stash_buffer[fd], fd);
	if (!stash_buffer[fd] || !*stash_buffer[fd])
	{
		free(stash_buffer[fd]);
		stash_buffer[fd] = NULL;
		return (NULL);
	}
	i = 0;
	while (stash_buffer[fd][i] && stash_buffer[fd][i] != '\n')
		i++;
	if (stash_buffer[fd][i] == '\n')
		i++;
	line = ft_substr(stash_buffer[fd], 0, i);
	rest = ft_substr(stash_buffer[fd], i, ft_strlen(stash_buffer[fd]) - i);
	free(stash_buffer[fd]);
	stash_buffer[fd] = rest;
	return (line);
}
