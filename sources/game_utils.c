/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:19:12 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/27 12:20:29 by mbentale         ###   ########.fr       */
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
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->base_image->img, 0, 0);
	return (0);
}

void	load_images(t_vars *vars)
{
	vars->background = add_image(vars, BACKGROUND);
	vars->wall = add_image(vars, WALL);
	vars->player_right = add_image(vars, PLAYER_TO_RIGHT);
	vars->player_left = add_image(vars, PLAYER_TO_LEFT);
	vars->collectible = add_image(vars, COLLECTIBLE);
	vars->exit = add_image(vars, EXIT);
	vars->open_door = add_image(vars, OPEN_DOOR);
}

void	game_won(t_vars *vars)
{
	if (vars->map[vars->pos.y / TILE_SIZE][vars->pos.x / TILE_SIZE] == 'E'
		&& vars->collected == vars->total_collectibles)
	{
		ft_printf("\033[1;32m\nCongratulations! YOU HAVE WON!\n\033[0m");
		ft_free(vars, 0);
	}
}
