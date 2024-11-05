/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:04:07 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/04 16:22:26 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr;
	size_t i;
	char char_to_find;

	ptr = s;
	i = 0;
	char_to_find = (char) n;
	
	while (i<= n)
	{
		if(ptr[i] == n)
			return (void *)(ptr[i]);
		i++;
	}
	return (0);
}

