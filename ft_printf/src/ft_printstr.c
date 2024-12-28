/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:37:47 by mbentale          #+#    #+#             */
/*   Updated: 2024/11/13 14:49:39 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		(*count)++;
		i++;
	}
}
