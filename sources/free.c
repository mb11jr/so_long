/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:35:05 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/27 14:49:13 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_destroy_image(t_vars *vars, t_obj *obj)
{
	mlx_destroy_image(vars->mlx, obj->img);
	free(obj);
}

static void	free_tiles(t_vars *vars)
{
	if (vars->base_image)
		ft_destroy_image(vars, vars->base_image);
	if (vars->background)
		ft_destroy_image(vars, vars->background);
	if (vars->wall)
		ft_destroy_image(vars, vars->wall);
	if (vars->player_right)
		ft_destroy_image(vars, vars->player_right);
	if (vars->player_left)
		ft_destroy_image(vars, vars->player_left);
	if (vars->collectible)
		ft_destroy_image(vars, vars->collectible);
	if (vars->exit)
		ft_destroy_image(vars, vars->exit);
	if (vars->open_door)
		ft_destroy_image(vars, vars->open_door);
}

void	ft_free(t_vars *vars, int status)
{
	if (vars->map)
		free_map(vars->map, vars->win_height / TILE_SIZE);
	if (vars->mlx)
	{
		free_tiles(vars);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(status);
}

void	free_and_exit(t_vars *vars, int status, char *s)
{
	ft_printf("\033[1;31mError!\n\033[0m");
	ft_printf("\033[1m%s\033[0m\n", s);
	ft_free(vars, status);
}
