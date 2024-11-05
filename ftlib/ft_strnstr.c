/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:15 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/05 17:43:59 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(little);
	if (k == 0)
		return ((char *)big);
	while (big[i] && i != len)
	{
		if (big[i] == little[i])
		{
			while (big[i + j] == little[i + j])
			{
				if (j == k)
					return ((char *)big + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
