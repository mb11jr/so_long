/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:11:02 by mbentale          #+#    #+#             */
/*   Updated: 2024/11/13 10:59:07 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits_hex(unsigned int num)
{
	size_t	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

static void	ft_puthex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

void	ft_printhex(unsigned int value, const char c, int *count)
{
	if (value == 0)
		*count += write(1, "0", 1);
	else
	{
		ft_puthex(value, c);
		*count += count_digits_hex(value);
	}
}
