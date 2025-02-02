/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/02 09:23:59 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac <= 1)
		error_msg("No map specified!");
	if (ac > 2)
		error_msg("Too many arguments!");
	if (ac == 2 && !check_map_extension(av[1]))
		error_msg("Wrong file extension! Make sure it ends with .ber");
	ft_bzero(&vars, sizeof(t_vars));
	read_map(&vars, av[1]);
	map_parser(&vars);
	vars.mlx = mlx_init();
	load_images(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.win_width * TILE_SCALE,
			vars.win_height * TILE_SCALE, "Welcome to my 2D game");
	mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, render_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
