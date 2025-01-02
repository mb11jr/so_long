/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:57:13 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/02 12:16:03 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_map
{
	char	*path;
	char	**content;
	int		width;
	int		height;
}	t_map;


typedef struct	s_obj
{
    void    *img;
	int		width;
	int		height;
	int		x;
	int		y;
	char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
	// struct s_obj	*next;
}				t_obj;

typedef struct  s_vars
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_map		*map;
	t_obj		*base_image;
	t_obj		*background;
    t_obj		*wall;
	t_obj		*player;
	t_obj		*token;
}				t_vars;

#endif