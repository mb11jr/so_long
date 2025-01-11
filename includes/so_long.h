/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:30:52 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/11 12:24:33 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/include/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "mlx.h"
# include "structures.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 48
# define SPEED 24
# define BACKGROUND "./textures/Background/Background01.xpm"
# define WALL "./textures/Background/Wall01.xpm"
# define PLAYER "./textures/Player/shroom.xpm"
# define COLLECTIBLE "./textures/Background/key0.xpm"
# define EXIT "./textures/Exit/exit00.xpm"

t_obj			*add_image(t_vars *vars, char *filename, t_obj *img);
void			get_position(t_vars *vars);
void			put_pixel_img(t_vars *vars, int x, int y, int color);
unsigned int	get_pixel_img(t_obj *img, int x, int y);
void			put_img_to_img(t_vars *vars, t_obj *src, int x, int y);
int				render_game(t_vars *vars);
void			total_collectibles(t_vars *vars);
void			read_map(t_vars *vars, char *path);
void			map_error(char *s);
void			map_parser(t_vars *vars);
int				is_rectangular(t_vars *vars);
int				ft_linelen(char *s);
int				count_collectibles(t_vars *vars);
int				check_map_name(char *s);

#endif