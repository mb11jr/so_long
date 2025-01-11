/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/11 15:55:12 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	game_won(t_vars *vars)
{
	if (vars->map[vars->player->y / TILE_SIZE][vars->player->x
		/ TILE_SIZE] == 'E' && vars->collected == vars->total_collectibles)
	{
		ft_printf("Congratulations! YOU HAVE WON!\n");
		ft_printf("Is that the best you can do?");
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

int	keypress_handler(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->player->x;
	new_y = vars->player->y;
	ft_printf("Total moves: %d\n", ++vars->moves);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
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
	vars->collected = 0;
	vars->reachable_exit = 0;
	vars->reachable_collectibles = 0;
	vars->moves = 0;
	vars->total_collectibles = count_collectibles(vars);
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
	get_position(&vars);
	map_parser(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height,
			"Welcome to my 2D game");
	vars.map[vars.player->y / TILE_SIZE][vars.player->x / TILE_SIZE] = '0';
	mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, render_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
