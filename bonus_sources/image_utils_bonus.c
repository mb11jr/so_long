/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:31:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/27 11:45:15 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_pixel_img(t_vars *vars, int x, int y, int color)
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

static unsigned int	get_pixel_img(t_obj *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + y * img->line_length + x
		* img->bits_per_pixel / 8));
}

void	put_img_to_baseimage(t_vars *vars, t_obj *src, int x, int y)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (++i < src->width)
	{
		j = -1;
		while (++j < src->height)
		{
			k = -1;
			while (++k < TILE_SCALE)
			{
				l = -1;
				while (++l < TILE_SCALE)
					put_pixel_img(vars, (x + i) * TILE_SCALE + l, (y + j)
						* TILE_SCALE + k, get_pixel_img(src, i, j));
			}
		}
	}
}

void	put_scaledimg_to_baseimage(t_vars *vars, t_obj *src, t_point pos,
		t_point scale)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (++i < src->width)
	{
		j = -1;
		while (++j < src->height)
		{
			k = -1;
			while (++k < scale.y)
			{
				l = -1;
				while (++l < scale.x)
					put_pixel_img(vars, (pos.x + i) * scale.x + l, (pos.y + j)
						* scale.y + k, get_pixel_img(src, i, j));
			}
		}
	}
}
