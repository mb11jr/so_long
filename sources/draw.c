/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:44:20 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/28 10:01:21 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_vars *vars, int x, int y)
{
	if (vars->collected == vars->total_collectibles)
		put_img_to_baseimage(vars, vars->open_door, x * TILE_SIZE, y
			* TILE_SIZE);
	else
		put_img_to_baseimage(vars, vars->exit, x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_player(t_vars *vars)
{
	if (vars->direction)
		put_img_to_baseimage(vars, vars->player_left, vars->pos.x, vars->pos.y);
	else
		put_img_to_baseimage(vars, vars->player_right, vars->pos.x,
			vars->pos.y);
}

void	draw_each(t_vars *vars, t_point pos)
{
	if (vars->map[pos.x][pos.y] == '1')
		put_img_to_baseimage(vars, vars->wall, pos.y * TILE_SIZE, pos.x
			* TILE_SIZE);
	if (vars->map[pos.x][pos.y] == 'E')
		draw_exit(vars, pos.y, pos.x);
	if (vars->map[pos.x][pos.y] == 'C')
		put_scaledimg_to_baseimage(vars, vars->collectible, (t_point){pos.y
			* vars->collectible->width, pos.x * vars->collectible->height},
			(t_point){3 * TILE_SCALE, 3 * TILE_SCALE});
}

int	draw(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			put_img_to_baseimage(vars, vars->background, x * TILE_SIZE, y
				* TILE_SIZE);
			draw_each(vars, (t_point){y, x});
		}
	}
	draw_player(vars);
	return (0);
}
