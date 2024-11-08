/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:46:21 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 16:50:22 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//permet de separer une chaine en tableaux
//en utilisant c, renvoi un tableau de chaine
static int	ft_countword(char * s)
{
	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i] == c)
			cpt++;
		while (s[i] == c)
			i++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	cpt;
	size_t	i;
	char	**tab;
	size_t	index;


	tab = malloc(cpt + 2 * (sizeof(char *)));
	i = 0;
	while (tab[i])
	{
		index = ft_strindex((char *)s, c);
		s = s + index;
		tab[i] = ft_substr(s, index, (unsigned long)ft_strchr(s + 1, c));
		i++;
	}
	return (tab);
}
