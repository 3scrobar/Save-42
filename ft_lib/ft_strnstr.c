/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:15 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/04 16:50:17 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;
	int k;
	
	k = 0;
	i = 0;
	j = 0;

	while (big[i])
	{
		if(big[i] == little[i])
			while (big[i + j] == little[i] + j && j < len)
				j++;
		if(j == len)
			return (big[i]);
		j = 0;
		i++;
	}
	
}
