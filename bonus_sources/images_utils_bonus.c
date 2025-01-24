/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:31:36 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/24 21:43:55 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_obj	*add_image(t_vars *vars, char *filename)
{
	t_obj	*img;

	img = malloc(sizeof(t_obj));
	img->img = mlx_xpm_file_to_image(vars->mlx, filename, &img->width,
			&img->height);
	if (!img->img)
	{
		ft_printf("The file %s doesn't exist!", filename);
		ft_free(vars, 2);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
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
