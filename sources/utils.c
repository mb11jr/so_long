/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:19:12 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/16 10:29:20 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_vars *vars)
{
	vars->base_image = NULL;
	vars->background = add_image(vars, BACKGROUND, vars->background);
	vars->wall = add_image(vars, WALL, vars->wall);
	vars->player = add_image(vars, PLAYER, vars->player);
	vars->collectible = add_image(vars, COLLECTIBLE, vars->collectible);
	vars->exit = add_image(vars, EXIT, vars->exit);
}

void	game_init(t_vars *vars)
{
	get_player_position(vars);
	vars->collected = 0;
	vars->reachable_exit = 0;
	vars->reachable_collectibles = 0;
	vars->moves = 0;
	vars->total_collectibles = count_collectibles(vars);
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

	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if ((vars->map[j][i] == '1' || (vars->map[j][i] == 'E'
				&& vars->collected < vars->total_collectibles))
				&& do_overlap(x, y, i * TILE_SIZE, j * TILE_SIZE))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

// int	check_enemy_collision(t_vars *vars, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (vars->map[j])
// 	{
// 		i = 0;
// 		while (vars->map[j][i])
// 		{
// 			if (vars->map[j][i] == 'N'
// 				&& do_overlap(x, y, i * TILE_SIZE, j * TILE_SIZE))
// 				return (1);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (0);
// }

void	game_won(t_vars *vars)
{
	if (vars->map[vars->player->y / TILE_SIZE][vars->player->x
		/ TILE_SIZE] == 'E' && vars->collected == vars->total_collectibles)
	{
		ft_printf("Congratulations! YOU HAVE WON!\n");
		ft_printf("Is that the best you can do?\n");
		ft_printf("Look for a shorter path... :D");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	if (vars->map[vars->player->y / TILE_SIZE][vars->player->x
		/ TILE_SIZE] == 'C')
	{
		++vars->collected;
		vars->map[vars->player->y / TILE_SIZE][vars->player->x
			/ TILE_SIZE] = '0';
	}
}
