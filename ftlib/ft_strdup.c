/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:46:53 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 13:48:37 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));  // +1 pour le caractère nul
	if (dest == NULL)
		return (NULL);

	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

