/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:30:52 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/02 12:33:06 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "structures.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/include/ft_printf.h"

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280
# define TILE_SIZE 48
# define BASE_IMAGE "./textutes/Background/Baseimage.xpm"
# define BACKGROUND "./textures/Background/Background01.xpm"
# define WALL "./textures/Background/Wall01.xpm"
# define PLAYER "./textures/Player/shroom.xpm"
# define TOKEN "./textures/Background/key0.xpm"

char			**read_map(const char *filename);
int				total_width(char *filename);
int				total_height(char *filename);
void			get_position(t_vars *vars);
void			put_pixel_img(t_vars *vars, t_obj *img, int x, int y, int color);
unsigned 		get_pixel_img(t_obj *img, int x, int y);
void			put_img_to_img(t_vars *vars, t_obj *dst, t_obj *src, int x, int y);
#endif