/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:41:53 by mbentale          #+#    #+#             */
/*   Updated: 2024/11/13 10:54:04 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits(int num)
{
	size_t	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

void	ft_printid(int value, int *count)
{
	ft_putnbr_fd(value, 1);
	*count += count_digits(value);
}
