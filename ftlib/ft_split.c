/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:46:21 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/08 17:57:01 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//permet de separer une chaine en tableaux
//en utilisant c, renvoi un tableau de chaine


char	**ft_split(char const *s, char c)
{
	
}

#include <stdio.h>

int	main(void)
{
	char * str;
	char 	c;
	char **tab;
	int i = 0;

	str = "l     r m";
	c = ' ';

	tab = ft_split(str,c);
	while (tab[i])
	{
		printf("%s \n",tab[i]);
		i++;
	}
}

