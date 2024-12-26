/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:43:46 by mbentale          #+#    #+#             */
/*   Updated: 2024/11/13 10:41:08 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu(unsigned int value, int *count)
{
	if (value >= 10)
		ft_printu(value / 10, count);
	ft_putchar_fd(value % 10 + '0', 1);
	(*count)++;
}
