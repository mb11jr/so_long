/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:30:52 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/04 18:00:20 by mbentale         ###   ########.fr       */
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
# define PLAYER "./textures/Player/shroom2.xpm"
# define COLLECTIBLE "./textures/Background/key0.xpm"
# define EXIT "./textures/Background/exit.xpm"

void			read_map(t_vars *vars, char *path);
t_obj			*add_image(t_vars *vars, char *filename, t_obj *img);
void			get_position(t_vars *vars);
void			put_pixel_img(t_vars *vars, int x, int y, int color);
unsigned int	get_pixel_img(t_obj *img, int x, int y);
void			put_img_to_img(t_vars *vars, t_obj *src, int x, int y);
int				draw_background(t_vars *vars);
int				draw_wall(t_vars *vars);
int				draw_player(t_vars *vars);
int				draw_token(t_vars *vars);
int				render_game(t_vars *vars);
void			total_collectibles(t_vars *vars, char *path);

#endif