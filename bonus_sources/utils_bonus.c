/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:55:35 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/27 14:55:23 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_game(t_vars *vars)
{
	if (vars->base_image)
		mlx_destroy_image(vars->mlx, vars->base_image->img);
	free(vars->base_image);
	vars->base_image = malloc(sizeof(t_obj));
	vars->base_image->img = mlx_new_image(vars->mlx, vars->win_width
			* TILE_SCALE, vars->win_height * TILE_SCALE);
	vars->base_image->addr = mlx_get_data_addr(vars->base_image->img,
			&vars->base_image->bits_per_pixel, &vars->base_image->line_length,
			&vars->base_image->endian);
	draw(vars);
	draw_count(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->base_image->img, 0, 0);
	return (0);
}

void	display_count(int keycode, t_vars *vars, int x, int y)
{
	if (!check_collision(vars, x, y) && (keycode == XK_w
			|| keycode == XK_Up || keycode == XK_a || keycode == XK_Left
			|| keycode == XK_s || keycode == XK_Down || keycode == XK_d
			|| keycode == XK_Right))
		++vars->moves;
}

void	update_player_position(int keycode, t_vars *vars, t_point *pos)
{
	if (keycode == XK_Escape)
	{
		ft_printf("\033[1;33mYou can always come back!\n\033[0m");
		ft_free(vars, 0);
	}
	if (keycode == XK_w || keycode == XK_Up)
		pos->y -= SPEED;
	if (keycode == XK_a || keycode == XK_Left)
	{
		pos->x -= SPEED;
		vars->direction = 1;
	}
	if (keycode == XK_s || keycode == XK_Down)
		pos->y += SPEED;
	if (keycode == XK_d || keycode == XK_Right)
	{
		pos->x += SPEED;
		vars->direction = 0;
	}
}

int	keypress_handler(int keycode, t_vars *vars)
{
	t_point	new_position;

	new_position.x = vars->pos.x;
	new_position.y = vars->pos.y;
	update_player_position(keycode, vars, &new_position);
	if (check_collision(vars, new_position.x, new_position.y))
		return (0);
	display_count(keycode, vars, new_position.x, new_position.y);
	vars->pos.x = new_position.x;
	vars->pos.y = new_position.y;
	game_won(vars);
	return (0);
}

int	close_handler(t_vars *vars)
{
	ft_printf("\033[1;33mYou can always come back!\n\033[0m");
	ft_free(vars, 0);
	return (0);
}
