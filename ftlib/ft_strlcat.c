/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:29 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/05 18:13:48 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = ft_strlen(dst);
	while (i != size - 1 && src[i])
	{
		dst[c + i] = src[i];
		i++;
	}
	dst[c + i] = 0;
	return (ft_strlen(dst) + ft_strlen(src));
}
