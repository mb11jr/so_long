/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:35:05 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/25 12:11:41 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_image(t_vars *vars, t_obj *obj)
{
	mlx_destroy_image(vars->mlx, obj->img);
	free(obj);
}

void	ft_free(t_vars *vars, int status)
{
	if (vars->map)
		free_map(vars->map, vars->win_height / TILE_SIZE);
	if (!vars->mlx)
		exit(status);
	if (vars->base_image)
		ft_destroy_image(vars, vars->base_image);
	if (vars->background)
		ft_destroy_image(vars, vars->background);
	if (vars->wall)
		ft_destroy_image(vars, vars->wall);
	if (vars->player)
		ft_destroy_image(vars, vars->player);
	if (vars->collectible)
		ft_destroy_image(vars, vars->collectible);
	if (vars->exit)
		ft_destroy_image(vars, vars->exit);
	if (vars->open_door)
		ft_destroy_image(vars, vars->open_door);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(status);
}

void	free_and_exit(t_vars *vars, int status, char *s)
{
	ft_printf("Error!\n");
	ft_printf("%s\n", s);
	ft_free(vars, status);
}
