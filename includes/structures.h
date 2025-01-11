/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:57:13 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/11 14:43:44 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_obj
{
	void		*img;
	int			width;
	int			height;
	int			x;
	int			y;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_obj;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	char		**map;
	t_obj		*base_image;
	t_obj		*background;
	t_obj		*wall;
	t_obj		*player;
	t_obj		*collectible;
	t_obj		*exit;
	int			collected;
	int			total_collectibles;
	int			reachable_collectibles;
	int			moves;
	int			reachable_exit;
}				t_vars;

#endif