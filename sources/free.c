/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:35:05 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/20 15:12:29 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_vars *vars, t_obj *obj)
{
	mlx_destroy_image(vars->mlx, obj->img);
	free(obj);
}

void	free_images(t_vars *vars)
{
	free_map(vars->map, vars->win_height / TILE_SIZE);
	if (vars->mlx)
	{
		if (vars->base_image)
			ft_free(vars, vars->base_image);
		if (vars->background)
			ft_free(vars, vars->background);
		if (vars->wall)
			ft_free(vars, vars->wall);
		if (vars->player)
			ft_free(vars, vars->player);
		if (vars->collectible)
			ft_free(vars, vars->collectible);
		if (vars->exit)
			ft_free(vars, vars->exit);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(1);
}
