/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/07 17:42:52 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	res = ft_malloc_trim(s1,set);
	if (res == NULL)
		return (NULL);
	while (s1[i] && k != NULL)
	{
		k = ft_strchr(set,s1[i]);
		i++;
	}
	k ="";
	while (k == NULL)
	{
		k = ft_strchr(set,s1[i]);
		res[j] = s1[i+j];
		j++;
	}
	res[j] = 0;
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
