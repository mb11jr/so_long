/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:37:45 by mbentale          #+#    #+#             */
/*   Updated: 2025/01/16 16:07:23 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_printstr(char *str, int *count);
void	ft_printu(unsigned int value, int *count);
void	ft_printid(int id, int *count);
void	ft_printhex(unsigned int value, const char c, int *count);
void	ft_printp(unsigned long long value, int *count);

#endif