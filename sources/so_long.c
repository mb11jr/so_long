/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/02 21:36:51 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_handler(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if ((keycode == XK_w || keycode == XK_Up) && vars->player->y > 0)
		vars->player->y -= TILE_SIZE / 2;
	if ((keycode == XK_a || keycode == XK_Left) && vars->player->x > 0)
		vars->player->x -= TILE_SIZE / 2;
	if ((keycode == XK_s || keycode == XK_Down) && vars->player->y
		+ vars->player->height < vars->win_height)
		vars->player->y += TILE_SIZE / 2;
	if ((keycode == XK_d || keycode == XK_Right) && vars->player->x
		+ vars->player->width < vars->win_width)
		vars->player->x += TILE_SIZE / 2;
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

	vars.map = malloc(sizeof(t_map));
	vars.map->path = "maps/map0.ber";
	vars.win_height = TILE_SIZE * map_height(&vars);
	vars.win_width = TILE_SIZE * map_width(&vars);
	vars.mlx = mlx_init();
	load_images(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height,
			"Welcome to my 2D game");
	read_map(&vars);
	get_position(&vars);
	vars.map->content[vars.player->y / TILE_SIZE][vars.player->x / TILE_SIZE] = '0';
	mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, render_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
