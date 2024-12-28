/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:48:05 by mbentale          #+#    #+#             */
/*   Updated: 2024/11/13 10:55:17 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits_ptr(unsigned long long num)
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

static void	ft_putptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

void	ft_printp(unsigned long long value, int *count)
{
	*count += write(1, "0x", 2);
	if (value == 0)
		*count += write(1, "0", 1);
	else
	{
		ft_putptr(value);
		*count += count_digits_ptr(value);
	}
}
