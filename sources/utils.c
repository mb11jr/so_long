/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:36:31 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/02 11:48:40 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map->content[y])
	{
		x = 0;
		while (vars->map->content[y][x])
		{
			if (vars->map->content[y][x] == 'P')
			{
				vars->player->x = x * TILE_SIZE;
				vars->player->y = y * TILE_SIZE;		
			}
			x++;
		}
		y++;
	}
}

void	put_pixel_img(t_obj *img, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x <  && y >= 0 && y < vars->win_height)
	{
		pxl = vars->image->addr + (y * vars->image->line_length + x * vars->image->bits_per_pixel / 8);
		*(unsigned int*)pxl = color;
	}
}

unsigned int	get_pixel_img(t_obj *img, int x, int y)
{
	return (*(unsigned int*)img->addr + (y * img->line_length) + (x * img->bits_per_pixel / 8));
}

void	put_img_to_img(t_obj *dst, t_obj *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			
		}
	}
}
