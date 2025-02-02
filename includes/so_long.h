/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:30:52 by mbentale          #+#    #+#             */
/*   Updated: 2025/02/02 12:24:41 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/include/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "structures.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 48
# define SPEED 12
# define TILE_SCALE 2
# define BACKGROUND "./textures/background/background.xpm"
# define WALL "./textures/background/wall.xpm"
# define PLAYER_TO_RIGHT "./textures/player/player_to_right.xpm"
# define PLAYER_TO_LEFT "./textures/player/player_to_left.xpm"
# define EXIT "./textures/exit/closed_door.xpm"
# define OPEN_DOOR "./textures/exit/open_door.xpm"
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
# define COIN_00 "./textures/collectibles/coin00.xpm"
# define COIN_01 "./textures/collectibles/coin01.xpm"
# define COIN_02 "./textures/collectibles/coin02.xpm"
# define COIN_03 "./textures/collectibles/coin03.xpm"
# define COIN_04 "./textures/collectibles/coin04.xpm"
# define COIN_05 "./textures/collectibles/coin05.xpm"
# define ENEMY_00 "./textures/enemy/enemy00.xpm"
# define ENEMY_01 "./textures/enemy/enemy01.xpm"
# define ENEMY_02 "./textures/enemy/enemy02.xpm"
# define ENEMY_03 "./textures/enemy/enemy03.xpm"
# define ENEMY_04 "./textures/enemy/enemy04.xpm"
# define ENEMY_05 "./textures/enemy/enemy05.xpm"
# define ENEMY_06 "./textures/enemy/enemy06.xpm"
# define ENEMY_07 "./textures/enemy/enemy07.xpm"

void	draw_count(t_vars *vars);
int		draw(t_vars *vars);
int		render_game(t_vars *vars);
void	animate_coins(t_vars *vars);
void	animate_enemy(t_vars *vars);
void	ft_free(t_vars *vars, int status);
void	free_and_exit(t_vars *vars, int status, char *s);
void	load_count_images(t_vars *vars);
t_obj	*add_image(t_vars *vars, char *filename);
void	put_img_to_baseimage(t_vars *vars, t_obj *src, int x, int y);
void	put_scaledimg_to_baseimage(t_vars *vars, t_obj *src, t_point pos,
			t_point scale);
int		is_rectangular(t_vars *vars);
int		enclosed_in_walls(t_vars *vars);
int		check_exit_start(t_vars *vars);
int		validate_map(t_vars *vars);
void	free_map(char **map, int height);
void	map_parser(t_vars *vars);
int		check_map_extension(char *s);
int		ft_linelen(char *s);
void	error_msg(char *s);
void	read_map(t_vars *vars, char *path);
int		keypress_handler(int keycode, t_vars *vars);
int		close_handler(t_vars *vars);
void	load_images(t_vars *vars);
int		check_collision(t_vars *vars, int x, int y);

#endif