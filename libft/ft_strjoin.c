/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:34:41 by mbentale          #+#    #+#             */
/*   Updated: 2024/11/04 08:23:09 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc(len_s1 + len_s2 + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len_s1 + len_s2 + 1);
	ft_strlcat(res, s2, len_s1 + len_s2 + 1);
	res[len_s1 + len_s2] = '\0';
	return (res);
}
