/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:36:12 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/16 16:04:57 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format_check(const char c, va_list args, int *count)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		++(*count);
	}
	else if (c == 's')
		ft_printstr(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_printid(va_arg(args, int), count);
	else if (c == 'u')
		ft_printu(va_arg(args, unsigned int), count);
	else if (c == 'x' || c == 'X')
		ft_printhex(va_arg(args, unsigned int), c, count);
	else if (c == 'p')
		ft_printp(va_arg(args, unsigned long long), count);
	else if (c != '\0')
	{
		ft_putchar_fd(c, 1);
		++(*count);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_count;

	total_count = 0;
	va_start(args, format);
	if (write(1, 0, 0))
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			total_count++;
		}
		else
		{
			format++;
			ft_format_check(*format, args, &total_count);
		}
		format++;
	}
	va_end(args);
	return (total_count);
}
