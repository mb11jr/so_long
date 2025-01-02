/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:36:31 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/02 16:14:36 by mbentale         ###   ########.fr       */
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

void	put_pixel_img(t_vars *vars, t_obj *img, int x, int y, int color)
{
	char	*pxl;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && x < vars->win_width && y >= 0 && y < vars->win_height)
	{
		pxl = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
		*(unsigned int*)pxl = color;
	}
}

unsigned int	get_pixel_img(t_obj *img, int x, int y)
{
	return (*(unsigned int*)(img->addr + y * img->line_length + x * img->bits_per_pixel / 8));
}

void	put_img_to_img(t_vars *vars, t_obj *dst, t_obj *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			put_pixel_img(vars, dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
