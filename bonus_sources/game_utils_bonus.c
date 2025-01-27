/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:19:12 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/27 12:20:31 by mbentale         ###   ########.fr       */
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

void	load_images(t_vars *vars)
{
	vars->background = add_image(vars, BACKGROUND);
	vars->wall = add_image(vars, WALL);
	vars->player_right = add_image(vars, PLAYER_TO_RIGHT);
	vars->player_left = add_image(vars, PLAYER_TO_LEFT);
	vars->enemy = add_image(vars, ENEMY);
	vars->collectible = add_image(vars, COLLECTIBLE);
	vars->exit = add_image(vars, EXIT);
	vars->open_door = add_image(vars, OPEN_DOOR);
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

void	game_won(t_vars *vars)
{
	if (vars->map[vars->pos.y / TILE_SIZE][vars->pos.x / TILE_SIZE] == 'E'
		&& vars->collected == vars->total_collectibles)
	{
		ft_printf("\033[1;32m\nCongratulations! YOU HAVE WON!\n\033[0m");
		ft_free(vars, 0);
	}
}

void	get_player_position(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->pos.x = x * TILE_SIZE;
				vars->pos.y = y * TILE_SIZE;
			}
			x++;
		}
		y++;
	}
}
