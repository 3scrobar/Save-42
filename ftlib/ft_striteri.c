/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:30:30 by root              #+#    #+#             */
/*   Updated: 2024/11/11 19:32:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_striteri(char *s, void (*f)(unsigned int,
char*)
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
		result[i] = f(i, s + i);  // Applique la fonction f à chaque caractère
		i++;
	}
	result[i] = '\0';  // Ajoute le caractère de fin de chaîne
	return (result);
}