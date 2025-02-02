/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:19:12 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/02 12:24:29 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_game(t_vars *vars)
{
	animate_coins(vars);
	animate_enemy(vars);
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


void	load_count_images(t_vars *vars)
{
	int			i;
	const char	*paths[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
		EIGHT, NINE};

	i = -1;
	while (++i < 10)
		vars->count[i] = add_image(vars, (char *)paths[i]);
}

void	load_coin_sprites(t_vars *vars)
{
	int		i;
	const char *paths[] = {COIN_00, COIN_01, COIN_02, COIN_03, COIN_04, COIN_05};
	
	i = -1;
	while(++i < 6)
		vars->coins[i] = add_image(vars, (char *)paths[i]);
}

void	load_enemy_sprites(t_vars *vars)
{
	int		i;
	const char *paths[] = {ENEMY_00, ENEMY_01, ENEMY_02, ENEMY_03, ENEMY_04, ENEMY_05, ENEMY_06, ENEMY_07};
	
	i = -1;
	while(++i < 8)
		vars->enemy[i] = add_image(vars, (char *)paths[i]);
}

void	load_images(t_vars *vars)
{
	vars->background = add_image(vars, BACKGROUND);
	vars->wall = add_image(vars, WALL);
	vars->player_right = add_image(vars, PLAYER_TO_RIGHT);
	vars->player_left = add_image(vars, PLAYER_TO_LEFT);
	// vars->enemy = add_image(vars, ENEMY);
	// vars->collectible = add_image(vars, COLLECTIBLE);
	vars->exit = add_image(vars, EXIT);
	vars->open_door = add_image(vars, OPEN_DOOR);
	load_count_images(vars);
	load_coin_sprites(vars);
	load_enemy_sprites(vars);
}

void	animate_coins(t_vars *vars)
{
	if (vars->coin_frame_count % 10 == 0)
	{
		vars->current_coin_frame++;
		if (vars->current_coin_frame >= 6)
			vars->current_coin_frame = 0;
	}
	vars->coin_frame_count++;
}

void	animate_enemy(t_vars *vars)
{
	if (vars->enemy_frame_count % 10 == 0)
	{
		vars->current_enemy_frame++;
		if (vars->current_enemy_frame >= 8)
			vars->current_enemy_frame = 0;
	}
	vars->enemy_frame_count++;
}
