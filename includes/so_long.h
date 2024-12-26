/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:30:52 by mbentale          #+#    #+#             */
/*   Updated: 2024/12/26 09:01:13 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280


typedef struct	s_obj {
    void    *img;
	int		width;
	int		height;
	int		x;
	int		y;
	struct s_obj	*next;
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

#define IMG00 "./assets/images/IMG00.xpm"


#endif