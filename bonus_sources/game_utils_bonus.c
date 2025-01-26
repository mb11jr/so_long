/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:19:12 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/26 14:45:26 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_vars *vars)
{
	vars->background = add_image(vars, BACKGROUND);
	vars->wall = add_image(vars, WALL);
	vars->player_right = add_image(vars, PLAYER_TO_RIGHT);
	vars->player_left = add_image(vars, PLAYER_TO_LEFT);
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
