/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:13:30 by toto              #+#    #+#             */
/*   Updated: 2024/11/10 23:18:06 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	char *result;

	if (!s || !f)
		return (NULL);
	
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1)); // +1 pour le caractère null '\0'
	if (!result)
		return (NULL);

	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);  // Applique la fonction f à chaque caractère
		i++;
	}
	result[i] = '\0';  // Ajoute le caractère de fin de chaîne
	return (result);
}
