/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:44:20 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/02 10:14:45 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_exit(t_vars *vars, int x, int y)
{
	if (vars->collected == vars->total_collectibles)
		put_img_to_baseimage(vars, vars->open_door, x * TILE_SIZE, y
			* TILE_SIZE);
	else
		put_img_to_baseimage(vars, vars->exit, x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_player(t_vars *vars)
{
	if (vars->direction)
		put_img_to_baseimage(vars, vars->player_left, vars->pos.x, vars->pos.y);
	else
		put_img_to_baseimage(vars, vars->player_right, vars->pos.x,
			vars->pos.y);
}

static void	draw_each(t_vars *vars, t_point pos)
{
	if (vars->map[pos.x][pos.y] == '1')
		put_img_to_baseimage(vars, vars->wall, pos.y * TILE_SIZE, pos.x
			* TILE_SIZE);
	if (vars->map[pos.x][pos.y] == 'E')
		draw_exit(vars, pos.y, pos.x);
	if (vars->map[pos.x][pos.y] == 'C')
		put_scaledimg_to_baseimage(vars, vars->coins[vars->current_coin_frame], (t_point){pos.y
			* vars->coins[0]->width, pos.x * vars->coins[0]->height},
			(t_point){3 * TILE_SCALE, 3 * TILE_SCALE});
	if (vars->map[pos.x][pos.y] == 'N')
		put_scaledimg_to_baseimage(vars, vars->enemy[vars->current_enemy_frame], (t_point){pos.y
			* vars->enemy[0]->width, pos.x * vars->enemy[0]->height},
			(t_point){2 * TILE_SCALE, 2 * TILE_SCALE});
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

void	draw_count(t_vars *vars)
{
	char	*str;
	int		i;
	t_obj	*img;

	str = ft_itoa(vars->moves);
	i = 0;
	while (str[i])
	{
		img = vars->count[str[i] - '0'];
		put_scaledimg_to_baseimage(vars, img,
			(t_point){(i * img->width) + (img->width * 0.5),
			(img->height * 0.25)}, (t_point){3 * TILE_SCALE, 3 * TILE_SCALE});
		i++;
	}
	free(str);
}
