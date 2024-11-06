/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:52:17 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 16:59:59 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{

	size_t			i;
	size_t			j;
	unsigned char *	dest;

	i = 0;
	j = 0;

	dest = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1));
	if (!dest)
		return (NULL);
	while (!s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (!s2[i])
	{
		dest[i + j] = s2[j];
		j++;
	}
	
}