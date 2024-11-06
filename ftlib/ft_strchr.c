/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:31:43 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 13:58:36 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	if (ft_isprint(c) == 1)
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] != c)
			return (NULL);
		return ((char *)s + i);
}
