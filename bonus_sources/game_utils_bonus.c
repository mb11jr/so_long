/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:19:12 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/25 12:32:52 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_vars *vars)
{
	vars->background = add_image(vars, BACKGROUND);
	vars->wall = add_image(vars, WALL);
	vars->player = add_image(vars, PLAYER);
	vars->collectible = add_image(vars, COLLECTIBLE);
	vars->exit = add_image(vars, EXIT);
	vars->open_door = add_image(vars, OPEN_DOOR);
}

void	load_count_images(t_vars *vars)
{
	int			i;
	const char	*paths[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
		EIGHT, NINE};

	i = -1;
	while (++i < 10)
		vars->count[i] = add_image(vars, (char *)paths[i]);
}

int	do_overlap(int ax, int ay, int bx, int by)
{
	if (ax + TILE_SIZE <= bx || ax >= bx + TILE_SIZE)
		return (0);
	if (ay + TILE_SIZE <= by || ay >= by + TILE_SIZE)
		return (0);
	return (1);
}

int	check_wall_collision(t_vars *vars, int x, int y)
{
	int	i;
	int	j;

	j = -1;
	while (vars->map[++j])
	{
		i = -1;
		while (vars->map[j][++i])
		{
			if (!do_overlap(x, y, i * TILE_SIZE, j * TILE_SIZE))
				continue ;
			if (vars->map[j][i] == '1' || (vars->map[j][i] == 'E'
					&& vars->collected < vars->total_collectibles))
				return (1);
			if (vars->map[j][i] == 'C')
			{
				++vars->collected;
				vars->map[j][i] = '0';
				return (0);
			}
		}
	}
	return (0);
}

void	game_won(t_vars *vars)
{
	if (vars->map[vars->pos.y / TILE_SIZE][vars->pos.x / TILE_SIZE] == 'E'
		&& vars->collected == vars->total_collectibles)
	{
		ft_printf("\n\nCongratulations! YOU HAVE WON!\n");
		ft_printf("______________________________\n");
		ft_printf("Is that the best you can do?\n");
		ft_printf("______________________________\n");
		ft_printf("Find a shorter path... :D");
		ft_free(vars, 0);
	}
}
