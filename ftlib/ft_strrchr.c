/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:48:17 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 15:32:05 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
//cherche un char dans une str et retourne le debut de lq chaine a lenver
char	*ft_strrchr(const char *s, size_t c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
