/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:36:31 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/25 11:56:59 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->pos.x = x * TILE_SIZE;
				vars->pos.y = y * TILE_SIZE;
			}
			x++;
		}
		y++;
	}
}

void	put_pixel_img(t_vars *vars, int x, int y, int color)
{
	char	*pxl;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && x < vars->win_width * TILE_SCALE && y >= 0
		&& y < vars->win_height * TILE_SCALE)
	{
		pxl = vars->base_image->addr + (y * vars->base_image->line_length + x
				* vars->base_image->bits_per_pixel / 8);
		*(unsigned int *)pxl = color;
	}
}

unsigned int	get_pixel_img(t_obj *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + y * img->line_length + x
		* img->bits_per_pixel / 8));
}
