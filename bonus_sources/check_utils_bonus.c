/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:31:46 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/28 09:49:16 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_overlap(t_shape a, t_shape b)
{
	if (a.x + a.w <= b.x || a.x >= b.x + b.w)
		return (0);
	if (a.y + a.h <= b.y || a.y >= b.y + b.h)
		return (0);
	return (1);
}

static void	init_shape(t_vars *vars, t_shape *shape, t_point pos)
{
	if (vars->map[pos.y][pos.x] == '1')
		*shape = (t_shape){pos.x * TILE_SIZE, pos.y * TILE_SIZE, TILE_SIZE,
			TILE_SIZE};
	if (vars->map[pos.y][pos.x] == 'C')
		*shape = (t_shape){pos.x * TILE_SIZE + 3, pos.y
			* TILE_SIZE + 3, TILE_SIZE
			- 3 - 3, TILE_SIZE - 3 - 3};
	if (vars->map[pos.y][pos.x] == 'E')
		*shape = (t_shape){pos.x * TILE_SIZE + 3, pos.y
			* TILE_SIZE, TILE_SIZE
			- 3 - 4, TILE_SIZE};
	if (vars->map[pos.y][pos.x] == 'N')
		*shape = (t_shape){pos.x * TILE_SIZE + 5, pos.y
			* TILE_SIZE + 5, TILE_SIZE - 5 - 5,
			TILE_SIZE - 5 - 6};
}

static void	check_tile(t_vars *vars, t_point pos)
{
	if (vars->map[pos.y][pos.x] == 'C')
	{
		++vars->collected;
		vars->map[pos.y][pos.x] = '0';
	}
	if (vars->map[pos.y][pos.x] == 'N')
	{
		ft_printf("\033[1;31m\nGAME OVER!\033[0m\n");
		ft_free(vars, 4);
	}
	if (vars->map[pos.y][pos.x] == 'E'
		&& vars->collected == vars->total_collectibles)
	{
		ft_printf("\033[1;32m\nCongratulations! YOU HAVE WON!\n\033[0m");
		vars->moves++;
		ft_free(vars, 0);
	}
}

int	check_collision(t_vars *vars, int x, int y)
{
	int		i;
	int		j;
	t_shape	player;
	t_shape	block;

	player = (t_shape){x + 9, y + 9, TILE_SIZE - 9 - 9, TILE_SIZE - 9 - 9};
	j = -1;
	while (vars->map[++j])
	{
		i = -1;
		while (vars->map[j][++i])
		{
			init_shape(vars, &block, (t_point){i, j});
			if (!check_overlap(player, block))
				continue ;
			if (vars->map[j][i] == '1' || (vars->map[j][i] == 'E'
					&& vars->collected < vars->total_collectibles))
				return (1);
			check_tile(vars, (t_point){i, j});
		}
	}
	return (0);
}
