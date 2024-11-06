/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:31:56 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 16:49:40 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start,
size_t len)
{
	int				i;
	unsigned char *	str;
	
	i = start;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i - start]
	}
	
}
