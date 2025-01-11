/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:05:32 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/11 15:03:12 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_vars *vars)
{
	int	i;
	int	len;

	len = ft_linelen(vars->map[0]);
	i = 1;
	while (vars->map[i])
	{
		if (ft_linelen(vars->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	enclosed_in_walls(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[0][j] && vars->map[vars->win_height / TILE_SIZE - 1][j])
	{
		if (vars->map[0][j] != '1' || vars->map[vars->win_height / TILE_SIZE
			- 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	while (vars->map[i] && i != vars->win_height / TILE_SIZE - 1)
	{
		if (vars->map[i][0] != '1' || vars->map[i][ft_linelen(vars->map[i])
			- 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_exit_start(t_vars *vars)
{
	int	i;
	int	j;
	int	count_exit;
	int	count_player;

	count_exit = 0;
	count_player = 0;
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'E')
				count_exit++;
			if (vars->map[i][j] == 'P')
				count_player++;
			if (count_exit > 1 || count_player > 1)
				return (0);
		}
	}
	if (count_exit == 0 || count_player == 0)
		return (0);
	return (1);
}

int	valid_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] != '1' && vars->map[i][j] != 'C'
				&& vars->map[i][j] != 'E' && vars->map[i][j] != '0'
				&& vars->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_collectibles(t_vars *vars)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
