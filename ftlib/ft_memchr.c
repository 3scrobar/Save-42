/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:04:07 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/05 17:32:42 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	char				char_to_find;

	ptr = s;
	i = 0;
	char_to_find = (char) c;
	while (i <= n)
	{
		if (ptr[i] == n)
			return ((void *) &ptr[i]);
		i++;
	}
	return (0);
}
