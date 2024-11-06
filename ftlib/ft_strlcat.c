/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:29 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 11:27:15 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	initsrc;

	i = 0;
	c = ft_strlen(dst);
	initsrc = ft_strlen(src);
	while (i != size - 1 && src[i])
	{
		dst[c + i] = src[i];
		i++;
	}
	if
	dst[c + i] = 0;
	if (size < initsrc)
		return (initsrc + c);
	else
		return (initsrc + c);
		
}
