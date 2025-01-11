/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:46:14 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/11 15:01:32 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] == 'r' && s[i - 1] == 'e' && s[i - 2] == 'b' && s[i - 3] == '.')
		return (1);
	return (0);
}

void	total_collectibles(t_vars *vars)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
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
