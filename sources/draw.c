/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:44:20 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/22 21:42:20 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			put_img_to_img(vars, vars->background, x * TILE_SIZE, y
				* TILE_SIZE);
			if (vars->map[y][x] == '1')
				put_img_to_img(vars, vars->wall, x * TILE_SIZE, y * TILE_SIZE);
			if (vars->map[y][x] == 'C')
				put_img_to_img(vars, vars->collectible, x * TILE_SIZE, y
					* TILE_SIZE);
			if (vars->map[y][x] == 'E')
				put_img_to_img(vars, vars->exit, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	put_img_to_img(vars, vars->player, vars->player->x, vars->player->y);
	return (0);
}

int	render_game(t_vars *vars)
{
	if (vars->base_image)
		mlx_destroy_image(vars->mlx, vars->base_image->img);
	free(vars->base_image);
	vars->base_image = malloc(sizeof(t_obj));
	vars->base_image->img = mlx_new_image(vars->mlx, vars->win_width * TILE_SCALE,
			vars->win_height * TILE_SCALE);
	vars->base_image->addr = mlx_get_data_addr(vars->base_image->img,
			&vars->base_image->bits_per_pixel, &vars->base_image->line_length,
			&vars->base_image->endian);
	draw(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->base_image->img, 0, 0);
	return (0);
}
