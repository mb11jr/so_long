/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:30:52 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/26 12:22:40 by mbentale         ###   ########.fr       */
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
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 48
# define PADDING 8
# define SPEED 12
# define TILE_SCALE 2
# define BACKGROUND "./textures/Background/Background01.xpm"
# define WALL "./textures/Background/Wall.xpm"
# define PLAYER "./textures/Player/player_to_right.xpm"
# define COLLECTIBLE "./textures/Collectibles/fruit.xpm"
# define EXIT "./textures/Exit/closed_door.xpm"
# define OPEN_DOOR "./textures/Exit/open_door.xpm"
# define ZERO "./textures/numbers/0.xpm"
# define ONE "./textures/numbers/1.xpm"
# define TWO "./textures/numbers/2.xpm"
# define THREE "./textures/numbers/3.xpm"
# define FOUR "./textures/numbers/4.xpm"
# define FIVE "./textures/numbers/5.xpm"
# define SIX "./textures/numbers/6.xpm"
# define SEVEN "./textures/numbers/7.xpm"
# define EIGHT "./textures/numbers/8.xpm"
# define NINE "./textures/numbers/9.xpm"

void			draw_exit(t_vars *vars, int x, int y);
void			draw_count(t_vars *vars);
int				draw(t_vars *vars);
int				render_game(t_vars *vars);
void			ft_destroy_image(t_vars *vars, t_obj *obj);
void			ft_free(t_vars *vars, int status);
void			free_and_exit(t_vars *vars, int status, char *s);
void			load_count_images(t_vars *vars);
t_obj			*add_image(t_vars *vars, char *filename);
void			put_pixel_img(t_vars *vars, int x, int y, int color);
unsigned int	get_pixel_img(t_obj *img, int x, int y);
void			put_img_to_baseimage(t_vars *vars, t_obj *src, int x, int y);
void			put_scaledimg_to_baseimage(t_vars *vars, t_obj *src,
					t_point pos, t_point scale);
int				is_rectangular(t_vars *vars);
int				enclosed_in_walls(t_vars *vars);
int				check_exit_start(t_vars *vars);
int				validate_map(t_vars *vars);
void			flood_fill(t_vars *vars, char **map, int x, int y);
char			**clone_map(char **original, int height, int width);
void			free_map(char **map, int height);
int				check_path(t_vars *vars);
void			map_parser(t_vars *vars);
int				check_map_extension(char *s);
int				ft_linelen(char *s);
void			error_msg(char *s);
int				map_height(t_vars *vars, int fd);
void			read_map(t_vars *vars, char *path);
void			display_count(int keycode, t_vars *vars, int x, int y);
int				keypress_handler(int keycode, t_vars *vars);
int				close_handler(t_vars *vars);
void			load_images(t_vars *vars);
int				check_overlap(t_shape a, t_shape b);
int				check_wall_collision(t_vars *vars, int x, int y);
void			game_won(t_vars *vars);

#endif