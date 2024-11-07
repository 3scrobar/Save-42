/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/07 20:49:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	yes;
	size_t	loc;

	loc = 0;
	yes = 0;
	i = 0;
	res = ft_malloc_trim(s1,set);
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		yes = ft_searchchar(s1[i],set);
		if (yes)
			loc = i;
		i++;
	}
	return (res);
}
static char	*ft_malloc_trim(char * s1, char const *set)
{
	size_t	cpt;
	size_t	i;
	char	*res;
	
	i = 0;
	cpt = 0;
	while (s1[i])
	{
		if (s1[i] == set)
			cpt++;
		i++;
	}
	res = malloc(sizeof(char) * (ft_strlen(s1) - cpt));
	if (res == NULL)
		return (NULL);
		
}
