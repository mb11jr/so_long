/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:30:52 by mbentale          #+#    #+#             */
/*   Updated: 2024/12/31 17:34:06 by mbentale         ###   ########.fr       */
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
# define BACKGROUND "./textures/Background/Background01.xpm"
# define WALL "./textures/Background/Wall01.xpm"
# define PLAYER "./textures/Player/shroom.xpm"
# define TOKEN "./textures/Background/key0.xpm"

char    **read_map(const char *filename);
int     total_width(char *filename);
int     total_height(char *filename);
void     get_position(t_vars *vars);
#endif