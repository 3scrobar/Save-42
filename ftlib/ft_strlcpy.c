/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:00 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/05 16:57:19 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	c;
	size_t	i;

	i = 0;
	s = size - 1;
	c = ft_strlen(dst);
	while (s != 0)
	{
		dst[c + i] = src[i];
		s--;
		i++;
	}
	dst[c + i + 1] = '\0';
	return (ft_strlen(src));
}
