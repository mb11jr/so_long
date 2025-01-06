/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:11:32 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/05 12:11:46 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangular(t_vars *vars, char *path)
{
	int i;
	int len;

	read_map(vars, path);
	len = ft_strlen(vars->map[0]);
	i = 1;
	while (vars->map[i])
	{
		if (ft_strlen(vars->map[i]) != len)
		{
			ft_printf("The map is not rectangular!");
			exit(0);
		}			
		i++;
	}
}