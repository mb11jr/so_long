/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:36:31 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/25 10:52:33 by mbentale         ###   ########.fr       */
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
		ft_printf("The file [%s] doesn't exist!", filename);
		ft_free(vars, 2);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
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
					put_pixel_img(vars, (i + x) * TILE_SCALE + l, (j + y)
						* TILE_SCALE + k, get_pixel_img(src, i, j));
			}
		}
	}
}
