/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/04 17:44:35 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_position(t_vars *vars)
{
	// int count;
	// count = 0;
	if (vars->map[vars->player->y / TILE_SIZE][vars->player->x
		/ TILE_SIZE] == 'C')
	{
		++vars->collected;
		// ft_printf("Collected items: %d\n", vars->collected);
		vars->map[vars->player->y / TILE_SIZE][vars->player->x
			/ TILE_SIZE] = '0';
		// if (vars->map[vars->player->y / TILE_SIZE][vars->player->x / TILE_SIZE] == 'E')
			
	}
}

int	do_overlap(int ax, int ay, int bx, int by)
{
	if (ax + TILE_SIZE <= bx || ax >= bx + TILE_SIZE)
		return (0);
	if (ay + TILE_SIZE <= by || ay >= by + TILE_SIZE)
		return (0);
	return (1);
}

	
// 	if (vars->map[])
// }

// 	if (vars->map[])
// }
int	keypress_handler(int keycode, t_vars *vars)
{
	int new_x = vars->player->x;
	int new_y = vars->player->y;
	ft_printf("Total moves: %d\n", ++vars->moves);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == XK_w || keycode == XK_Up)
		new_y -= SPEED;
	if (keycode == XK_a || keycode == XK_Left)
		new_x -= SPEED;
	if (keycode == XK_s || keycode == XK_Down)
		new_y += SPEED;
	if (keycode == XK_d || keycode == XK_Right)
		new_x += SPEED;

	int x, y;
	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			char tile = vars->map[y][x];
			if ((tile == '1' || (tile == 'E' && vars->collected < vars->total_collectibles)) && do_overlap(new_x, new_y, x * TILE_SIZE, y * TILE_SIZE))
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	vars->player->x = new_x;
	vars->player->y = new_y;
	update_player_position(vars);

	if (vars->map[vars->player->y / TILE_SIZE][vars->player->x / TILE_SIZE] == 'E' &&
		vars->collected == vars->total_collectibles)
	{
		ft_printf("Congratulations! YOU HAVE WON!\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	close_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	load_images(t_vars *vars)
{
	vars->base_image = NULL;
	// vars->wall = malloc(sizeof(t_obj));
	// if (!vars->wall)
	// {
	// 	free(vars->map);
	// 	free(vars->wall);
	// }
	// vars->player = malloc(sizeof(t_obj));
	// if (!vars->player)
	// {
	// 	free(vars->map);
	// 	free(vars->wall);
	// 	free(vars->player);
	// }
	// vars->background = malloc(sizeof(t_obj));
	// vars->token = malloc(sizeof(t_obj));
	vars->background = add_image(vars, BACKGROUND, vars->background);
	vars->wall = add_image(vars, WALL, vars->wall);
	vars->player = add_image(vars, PLAYER, vars->player);
	vars->token = add_image(vars, COLLECTIBLE, vars->token);
	vars->exit = add_image(vars, EXIT, vars->exit);
}

int	main(void)
{
	t_vars	vars;

	vars.collected = 0;
	vars.moves = 0;
	total_collectibles(&vars, "maps/map0.ber");
	vars.mlx = mlx_init();
	load_images(&vars);
	read_map(&vars, "maps/map0.ber");
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height,
			"Welcome to my 2D game");
	get_position(&vars);
	vars.map[vars.player->y / TILE_SIZE][vars.player->x / TILE_SIZE] = '0';
	mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, render_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
