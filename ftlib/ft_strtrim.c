/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 12:57:38 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	yes;
	size_t	loc;
	size_t	stop;

	stop = 0;
	loc = 0;
	yes = 0;
	i = 0;
	res = ft_malloc_trim(s1,set);
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		yes = ft_searchchar(s1[i], set);
		stop = ft_searchchar(s1[i + 1],set);
		if (yes == 1 && stop == 0)
			loc = i + 1;
		if (stop == '\0' && yes == 1)
			stop = i + 1;
		i++;
	}
	return (ft_movestr(s1,loc,stop));
}
static char *ft_movestr(char *str, size_t start ,size_t stop)
{
	size_t	i;

	i =0;
	while (i <= stop)
	{
		str[i] = str[i +start];
		i++;
	}
	str[i] = '\0'
	return (str);
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
