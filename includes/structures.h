/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:57:13 by mbentale          #+#    #+#             */
/*   Updated: 2024/12/28 09:58:31 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_map
{
	int	width;
	int	height;
}	t_game;

typedef struct	s_obj
{
    void    *img;
	int		width;
	int		height;
	int		x;
	int		y;
	// struct s_obj	*next;
    // char    *addr;
    // int     bits_per_pixel;
    // int     line_length;
    // int     endian;
}				t_obj;

typedef struct  s_vars
{
	void	*mlx;
	void	*win;
    t_obj    *img;
}               t_vars;

#endif