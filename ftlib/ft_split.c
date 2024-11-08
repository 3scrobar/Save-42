/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:46:21 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 17:33:59 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//permet de separer une chaine en tableaux
//en utilisant c, renvoi un tableau de chaine
static int	ft_strindex(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
static int	ft_countword(char *s, char c)
{
	int	i;
	int	cpt;

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
	return (i + 1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;
	size_t	index;
	int		word;

	word = ft_countword((char *)s, c);
	tab = (char **)malloc((word + 1 )* (sizeof(char *)));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < word)
	{
		index = ft_strindex((char *)s, c);
		tab[i] = ft_substr(s, index, (unsigned long)ft_strchr(s + 1, c));
		if (tab[i] == NULL)
			return (tab);
		s = s + index;
		i++;
	}
	return (tab);
}

#include <stdio.h>

int	main(void)
{
	char * str;
	char 	c;
	char **tab;
	int i = 0;

	str = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	c = ' ';

	tab = ft_split(str,c);
	while (tab[i])
	{
		printf("%s \n",tab[i]);
		i++;
	}
}

