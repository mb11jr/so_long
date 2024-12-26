/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:31:20 by mbentale          #+#    #+#             */
/*   Updated: 2024/12/26 09:01:31 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./mlx_linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	keypress_handler(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape) 
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->img);
		free(vars);
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

int	destroy_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->img);
	free(vars);
	exit(0);
	return (0);
}

// void ft_put_pixel(t_img *img, int x, int y, int color)
// {
//     char *pxl;
    
//     if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
//     {
//         pxl = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
//         *(unsigned int *)pxl = color;
//     }
// }

int render_image(t_vars *vars)
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
    // while(x < 450)
    // {
    // 	y = 350;
    //     while(y < 450)
    //     {
    //     y++;
    //     }
    // x++;
    // }
	// mlx_do_sync(vars->mlx);
    return(1);
}
int	main()
{
    // void *mlx;
    // void *mlx_win;	
    // t_data img;
    // int width;
    // int height;

	t_vars	*vars;

	vars = NULL;
	vars = malloc(sizeof(t_vars));
	vars->img = malloc(sizeof(t_obj));
	vars->img->x = 50;
	vars->img->y = 50;
	vars->img->next = NULL;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Welcome to my 2D game");
	vars->img->img = mlx_xpm_file_to_image(vars->mlx, IMG00, &vars->img->width, &vars->img->height);
    // mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->img_width, vars->line_length);
	mlx_hook(vars->win, KeyPress, KeyPressMask, keypress_handler, vars);
	mlx_hook(vars->win, DestroyNotify, NoEventMask, destroy_handler, vars);
	mlx_loop_hook(vars->mlx, render_image, vars);
	// ft_put_pixel(vars->img, 0, 0, 0xFFDDFF);
    // mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	mlx_loop(vars->mlx);
    

	
	// vars->img = malloc(sizeof(t_img));
    // vars->img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    // vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 1920, 1080, "First test");
    // img.img=mlx_new_image(mlx, 1920, 1080);
    // my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    // mlx_loop(mlx);
}
