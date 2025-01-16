/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/16 10:29:04 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_count(int keycode, t_vars *vars, int x, int y)
{
	if (!check_wall_collision(vars, x, y) && (keycode == XK_w
			|| keycode == XK_Up || keycode == XK_a || keycode == XK_Left
			|| keycode == XK_s || keycode == XK_Down || keycode == XK_d
			|| keycode == XK_Right))
		ft_printf("Total moves: %d\n", ++vars->moves);
}

// void	destroy_win(int keycode, t_vars *vars, int x, int y)
// {
// 	if (keycode == XK_Escape || check_enemy_collision(vars, x, y))
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(1);
// 	}
// }
int	keypress_handler(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player->x;
	new_y = vars->player->y;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	// destroy_win(keycode, vars, vars->player->x, vars->player->y);
	if (keycode == XK_w || keycode == XK_Up)
		new_y -= SPEED;
	if (keycode == XK_a || keycode == XK_Left)
		new_x -= SPEED;
	if (keycode == XK_s || keycode == XK_Down)
		new_y += SPEED;
	if (keycode == XK_d || keycode == XK_Right)
		new_x += SPEED;
	if (check_wall_collision(vars, new_x, new_y))
		return (0);
	display_count(keycode, vars, new_x, new_y);
	vars->player->x = new_x;
	vars->player->y = new_y;
	game_won(vars);
	return (0);
}

int	close_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac <= 1)
		ft_error("No map specified.");
	if (ac > 2)
		ft_error("Too many arguments!");
	if (ac == 2 && !check_map_name(av[1]))
		ft_error("Wrong map file extension! Make sure it ends with .ber");
	vars.mlx = mlx_init();
	load_images(&vars);
	read_map(&vars, av[1]);
	game_init(&vars);
	map_parser(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height,
			"Welcome to my 2D game");
	mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, render_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
