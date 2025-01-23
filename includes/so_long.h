/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:30:52 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/23 17:34:07 by mbentale         ###   ########.fr       */
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
# define SPEED 12
# define TILE_SCALE 2
# define BACKGROUND "./textures/Background/Background01.xpm"
# define WALL "./textures/Background/Wall.xpm"
# define PLAYER "./textures/Player/shroom.xpm"
# define COLLECTIBLE "./textures/Collectibles/fruit.xpm"
# define EXIT "./textures/Exit/closed_door.xpm"
# define OPEN_DOOR "./textures/Exit/open_door.xpm"
# define TEXT "./textures/Count/totalmoves.xpm"
# define ZERO "./textures/Count/0.xpm"
# define ONE "./textures/Count/1.xpm"
# define TWO "./textures/Count/2.xpm"
# define THREE "./textures/Count/3.xpm"
# define FOUR "./textures/Count/4.xpm"
# define FIVE "./textures/Count/5.xpm"
# define SIX "./textures/Count/6.xpm"
# define SEVEN "./textures/Count/7.xpm"
# define EIGHT "./textures/Count/8.xpm"
# define NINE "./textures/Count/9.xpm"


t_obj			*add_image(t_vars *vars, char *filename);
void			get_player_position(t_vars *vars);
void			put_pixel_img(t_vars *vars, int x, int y, int color);
unsigned int	get_pixel_img(t_obj *img, int x, int y);
void			put_img_to_img(t_vars *vars, t_obj *src, int x, int y);
void	ft_put_img_to_img(t_vars *vars, t_obj *src, int x, int y);
int				render_game(t_vars *vars);
void			read_map(t_vars *vars, char *path);
void			map_parser(t_vars *vars);
int				is_rectangular(t_vars *vars);
int				enclosed_in_walls(t_vars *vars);
int				check_exit_start(t_vars *vars);
int				valid_map(t_vars *vars);
int				ft_linelen(char *s);
void			total_collectibles(t_vars *vars);
int				count_collectibles(t_vars *vars);
int				check_map_name(char *s);
void			game_won(t_vars *vars);
int				check_wall_collision(t_vars *vars, int x, int y);
void			game_init(t_vars *vars);
void			load_images(t_vars *vars);
void            load_count_images(t_vars *vars);
void			error_msg(char *s);
void			free_map(char **map, int height);
void	        ft_destroy_image(t_vars *vars, t_obj *obj);
void	        ft_free(t_vars *vars, int status);
#endif