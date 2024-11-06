/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:52:17 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 16:57:52 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1len;
	size_t			s2len;
	size_t			i;
	unsigned char *	dest;

	i = 0;
	s2len = ft_strlen(s2);
	s1len = ft_strlen(s1);
	dest = malloc(sizeof(char) * (s2len + s1len));
	if (!dest)
		return (NULL);
	while (!s1[i])
	{
		dest[i] =
	}
	
}
