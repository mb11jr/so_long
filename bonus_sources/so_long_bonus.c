/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/26 15:52:10 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_count(int keycode, t_vars *vars, int x, int y)
{
	if (!check_wall_collision(vars, x, y) && (keycode == XK_w
			|| keycode == XK_Up || keycode == XK_a || keycode == XK_Left
			|| keycode == XK_s || keycode == XK_Down || keycode == XK_d
			|| keycode == XK_Right))
		++vars->moves;
}

void	update_player_position(int keycode, t_vars *vars, t_point *pos)
{
	if (keycode == XK_Escape)
		ft_free(vars, 0);
	if (keycode == XK_w || keycode == XK_Up)
		pos->y -= SPEED;
	if (keycode == XK_a || keycode == XK_Left)
	{
		pos->x -= SPEED;
		vars->direction = 1;
	}
	if (keycode == XK_s || keycode == XK_Down)
		pos->y += SPEED;
	if (keycode == XK_d || keycode == XK_Right)
	{
		pos->x += SPEED;
		vars->direction = 0;
	}
}

int	keypress_handler(int keycode, t_vars *vars)
{
	t_point new_position;

	new_position.x = vars->pos.x;
	new_position.y = vars->pos.y;
	update_player_position(keycode, vars, &new_position);
	if (check_wall_collision(vars, new_position.x, new_position.y))
		return (0);
	display_count(keycode, vars, new_position.x, new_position.y);
	vars->pos.x = new_position.x;
	vars->pos.y = new_position.y;
	game_won(vars);
	return (0);
}

int	close_handler(t_vars *vars)
{
	ft_free(vars, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac <= 1)
		error_msg("No map specified.");
	if (ac > 2)
		error_msg("Too many arguments!");
	if (ac == 2 && !check_map_extension(av[1]))
		error_msg("Wrong file extension! Make sure it ends with .ber");
	ft_bzero(&vars, sizeof(t_vars));
	read_map(&vars, av[1]);
	map_parser(&vars);
	vars.mlx = mlx_init();
	load_images(&vars);
	load_count_images(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.win_width * TILE_SCALE,
			vars.win_height * TILE_SCALE, "Welcome to my 2D game");
	mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, render_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
