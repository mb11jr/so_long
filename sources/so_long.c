/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 09:53:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/02 15:54:31 by mbentale         ###   ########.fr       */
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
	if ((keycode == XK_s || keycode == XK_Down) &&
		vars->player->y + vars->player->height < vars->win_height)
		vars->player->y += TILE_SIZE / 2;
	if ((keycode == XK_d || keycode == XK_Right) &&
		vars->player->x + vars->player->width < vars->win_width)
		vars->player->x += TILE_SIZE / 2;
	return (0);
}

int	close_handler(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

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
			{
				// put_img_to_img(vars->mlx, vars->win, vars->background->img, x * TILE_SIZE, y * TILE_SIZE);
				put_img_to_img(vars, vars->base_image, vars->background, x * TILE_SIZE, y * TILE_SIZE);
				
			}
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
			{
				// put_img_to_img(vars->mlx, vars->win, vars->wall->img, x * TILE_SIZE, y * TILE_SIZE);
				put_img_to_img(vars, vars->base_image, vars->wall, x * TILE_SIZE, y * TILE_SIZE);
				
			}
			x++;
		}
		y++;
	}
	return (0);
}


int	draw_player(t_vars *vars)
{
	// put_img_to_img(vars->mlx, vars->win, vars->player->img, vars->player->x, vars->player->y);
	put_img_to_img(vars, vars->base_image, vars->player, vars->player->x, vars->player->y);
	return (0);	
}

int	draw_token(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map->content[y])
	{
		x = 0;
		while (vars->map->content[y][x])
		{
			if (vars->map->content[y][x] == 'C')
			{
				
				// mlx_put_image_to_window(vars->mlx, vars->win, vars->token->img, x * TILE_SIZE, y * TILE_SIZE);
				put_img_to_img(vars, vars->base_image, vars->token, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
	return (0);
}
int	render_game(t_vars *vars)
{
	if (vars->base_image)
		mlx_destroy_image(vars->mlx, vars->base_image->img);
	free(vars->base_image);
	vars->base_image = malloc(sizeof(t_obj));
	vars->base_image->img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height);
	vars->base_image->addr = mlx_get_data_addr(vars->base_image->img, &vars->base_image->bits_per_pixel, &vars->base_image->line_length, &vars->base_image->endian);
	draw_background(vars);
	draw_wall(vars);
	draw_token(vars);
	draw_player(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->base_image->img, 0, 0);
	return (0);
}

int	load_images(t_vars *vars)
{
	vars->background->img = mlx_xpm_file_to_image(vars->mlx, BACKGROUND, &vars->background->width, &vars->background->height);
	vars->background->addr = mlx_get_data_addr(vars->background->img, &vars->background->bits_per_pixel, &vars->background->line_length, &vars->background->endian);
	vars->wall->img = mlx_xpm_file_to_image(vars->mlx, WALL, &vars->wall->width, &vars->wall->height);
	vars->wall->addr = mlx_get_data_addr(vars->wall->img, &vars->wall->bits_per_pixel, &vars->wall->line_length, &vars->wall->endian);
	vars->player->img = mlx_xpm_file_to_image(vars->mlx, PLAYER, &vars->player->width, &vars->player->height);
	vars->player->addr = mlx_get_data_addr(vars->player->img, &vars->player->bits_per_pixel, &vars->player->line_length, &vars->player->endian);
	vars->token->img = mlx_xpm_file_to_image(vars->mlx, TOKEN, &vars->token->width, &vars->token->height);
	vars->token->addr = mlx_get_data_addr(vars->token->img, &vars->token->bits_per_pixel, &vars->token->line_length, &vars->token->endian); //optimize this :)
	return (0);
}

void	init_game(t_vars *vars)
{
	
	vars->base_image = NULL;
	vars->map = malloc(sizeof(t_map));
	if (!vars->map)
		free(vars->map);	
	vars->wall = malloc(sizeof(t_obj));
	if (!vars->wall)
	{
		free(vars->map);
		free(vars->wall);
	}
	vars->player = malloc(sizeof(t_obj));
	if (!vars->player)
	{
		free(vars->map);
		free(vars->wall);
		free(vars->player);
	}
	
	//use a linked list and ft_lstclear to free it ?
	
	vars->background = malloc(sizeof(t_obj));
	vars->token = malloc(sizeof(t_obj));
}
int	main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win_height = TILE_SIZE * total_height("maps/map0.ber");
	vars.win_width = TILE_SIZE * total_width("maps/map0.ber");
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "Welcome to my 2D game");
	init_game(&vars);
	vars.map->content = read_map("maps/map0.ber");
	load_images(&vars);
	get_position(&vars);
	vars.map->content[vars.player->y / TILE_SIZE][vars.player->x / TILE_SIZE] = '0';
	mlx_hook(vars.win, KeyPress, KeyPressMask, keypress_handler, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, close_handler, &vars);
	mlx_loop_hook(vars.mlx, render_game, &vars);
	mlx_loop(vars.mlx);
	// free(vars.mlx);
	return (0);
}
