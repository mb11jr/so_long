/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2024/12/28 12:40:09 by mbentale         ###   ########.fr       */
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
	if ((keycode == XK_w || keycode == XK_Up) && vars->img->y > 0)
		vars->img->y -= 10;
	if ((keycode == XK_a || keycode == XK_Left) && vars->img->x > 0)
		vars->img->x -= 10;
	if ((keycode == XK_s || keycode == XK_Down) &&
		vars->img->y + vars->img->height < WINDOW_HEIGHT)
		vars->img->y += 10;
	if ((keycode == XK_d || keycode == XK_Right) &&
		vars->img->x + vars->img->width < WINDOW_WIDTH)
		vars->img->x += 10;
	return (0);
}

int	close_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int draw_player(t_vars *vars)
{
    int x;
    int y;

    x = vars->img->x;
	y = vars->img->y;
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		mlx_clear_window(vars->mlx, vars->win);
    	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
	}
    return(0);
}

int	draw_background(t_vars *vars)
{
	int	x;
	int	y;

	if (!vars->img->img)
		return (1);
	y = 0;
	while (vars->map->content[y])
	{
		x = 0;
		while (vars->map->content[y][x])
		{
			if (vars->map->content[y][x] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, x * vars->img->width, y * vars->img->height);
			}
			x++;
		}
		y++;
	}
	return (0);	
}

int	main()
{
	t_vars	vars;

	vars.map = malloc(sizeof(t_map));
	vars.map->content = read_map("maps/map0.ber");
	vars.img = malloc(sizeof(t_obj));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Welcome to my 2D game");
	vars.img->img = mlx_xpm_file_to_image(vars.mlx, IMG00, &vars.img->width, &vars.img->height);
	// mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, draw_background, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	return (0);
}
