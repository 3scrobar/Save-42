/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 13:43:05 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	while (s1 && ft_strchr((char *)set, s1) != NULL)
		s1++;
	i = ft_strlen((char *)s1) - 1;
	while (ft_strrchr() != NULL)
	{
		
	}
	
	
}
