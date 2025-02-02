/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:57:13 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/02 10:14:25 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_obj
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_obj;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_shape
{
	int		x;
	int		y;
	int		w;
	int		h;
}			t_shape;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	char	**map;
	t_obj	*base_image;
	t_obj	*background;
	t_obj	*wall;
	t_obj	*player_right;
	t_obj	*player_left;
	t_point	pos;
	t_obj	*exit;
	t_obj	*open_door;
	t_obj	*count[10];
	t_obj	*coins[6];
	int		current_coin_frame;
	int		coin_frame_count;
	t_obj	*enemy[8];
	int		current_enemy_frame;
	int		enemy_frame_count;
	int		collected;
	int		total_collectibles;
	int		reachable_collectibles;
	int		moves;
	int		reachable_exit;
	int		direction;
}			t_vars;

#endif