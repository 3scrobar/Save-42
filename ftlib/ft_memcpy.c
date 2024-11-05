/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:34:33 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/05 17:55:03 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	c;

	c = 0;
	while (c != n)
	{
		*(unsigned char *)(dest + c) = *(unsigned char *)(src + c);
		c++;
	}
	return (dest);
}
