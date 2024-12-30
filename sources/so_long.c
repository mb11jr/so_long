/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2024/12/30 09:37:16 by mbentale         ###   ########.fr       */
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
		vars->player->y -= 10;
	if ((keycode == XK_a || keycode == XK_Left) && vars->player->x > 0)
		vars->player->x -= 10;
	if ((keycode == XK_s || keycode == XK_Down) &&
		vars->player->y + vars->player->height < vars->win_height)
		vars->player->y += 10;
	if ((keycode == XK_d || keycode == XK_Right) &&
		vars->player->x + vars->player->width < vars->win_width)
		vars->player->x += 10;
	return (0);
}

int	close_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

// int draw_player(t_vars *vars)
// {
	// if (x >= 0 && x < total_width("maps/map0.ber") && y >= 0 && y < total_width("maps/map0.ber"))
 	// {
 	// 	mlx_clear_window(vars->mlx, vars->win);
    	
//     return(0);
// }

int	draw_background(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map->content[y])
	{
		x = 0;
		while (vars->map->content[y][x])
		{
			if (vars->map->content[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background->img, x * vars->background->width, y * vars->background->height);
			x++;
		}
		y++;
	}
	return (0);	
}

int	draw_wall(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map->content[y])
	{
		x = 0;
		while (vars->map->content[y][x])
		{
			if (vars->map->content[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall->img, x * vars->wall->width, y * vars->wall->height);
			x++;
		}
		y++;
	}
	return (0);	
}


int	draw_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player->img, vars->player->x, vars->player->y);
	return (0);	
}

int	render_game(t_vars *vars)
{
	// mlx_clear_window(vars->mlx, vars->win);
	draw_background(vars);
	draw_wall(vars);
	draw_player(vars);
	return (0);
}

int	main()
{
	t_vars	vars;

	vars.map = malloc(sizeof(t_map));
	vars.map->content = read_map("maps/map0.ber");
	vars.wall = malloc(sizeof(t_obj));
	vars.player = malloc(sizeof(t_obj));
	vars.background = malloc(sizeof(t_obj));
	vars.mlx = mlx_init();
	vars.background->img = mlx_xpm_file_to_image(vars.mlx, BACKGROUND, &vars.background->width, &vars.background->height);
	vars.wall->img = mlx_xpm_file_to_image(vars.mlx, WALL, &vars.wall->width, &vars.wall->height);
	vars.player->img = mlx_xpm_file_to_image(vars.mlx, PLAYER, &vars.player->width, &vars.player->height);
	vars.player->x = 50;
	vars.player->y = 50;
	vars.win_height = vars.wall->height * total_height("maps/map0.ber");
	vars.win_width = vars.wall->width * total_width("maps/map0.ber");
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "Welcome to my 2D game");
	mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, render_game, &vars);
	mlx_loop(vars.mlx);
	// free(vars.mlx);
	return (0);
}
