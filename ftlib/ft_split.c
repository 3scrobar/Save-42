/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:46:21 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 15:28:18 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//permet de separer une chaine en tableaux
//en utilisant c, renvoi un tableau de chaine
char **ft_split(char const *s, char c)
{
	size_t	cpt;
	size_t	i;
	char	**tab;
	size_t	index;

	i = 0;
	while (*s != 0)
	{
		if (*s == c)
			cpt++;
		s++;
	}
	tab = malloc(cpt  + 2 * (sizeof(char *)));
	tab[cpt + 2] = 0;
	while (tab[i])
		{
			index = ft_strchr(s,c);
			s + index;
			tab[i] = ft_substr(s,index, ft_strchr(s + 1, c));
		}
	return (tab);
}
