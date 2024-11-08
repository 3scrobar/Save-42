/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:47:33 by root              #+#    #+#             */
/*   Updated: 2024/11/08 20:58:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

// Fonction pour compter le nombre de mots séparés par le caractère 'c'
static size_t ft_countword(const char *str, char c)
{
	size_t i; 
	size_t count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return count;
}

// Fonction pour calculer la longueur du mot à partir de l'index 'i'
static size_t ft_lenword(const char *s, size_t i, char c)
{
	size_t len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return len;
}

// Fonction qui extrait un mot de la chaîne en utilisant ft_substr
static char *ft_extract_word(const char *s, size_t start, size_t len)
{
	char *word;
	size_t i;

	i = 0;
	word = malloc(len + 1);
	if (!word)
		return NULL;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return word;
}

// Fonction pour découper la chaîne en mots
char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_count;
	char **tab;
	size_t word_len;

	i = 0;
	j = 0;
	if (!s)
		return NULL;
	word_count = ft_countword(s, c);
	tab = malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return NULL;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_len = ft_lenword(s, i, c);
			tab[j] = ft_extract_word(s, i, word_len);
			if (!tab[j])
				return NULL;
			i += word_len;
			j++;
		}
	}
	tab[j] = NULL;  // Terminer le tableau par NULL
	return (tab);
}

// // Fonction principale pour tester
// int main(void) {
// 	char *str = "l     r m fr ";
// 	char c = ' ';
// 	char **tab = ft_split(str, c);
// 	size_t i = 0;

// 	if (tab == NULL) {
// 		printf("Erreur d'allocation.\n");
// 		return 1;
// 	}

// 	// Affichage des mots extraits
// 	while (tab[i]) {
// 		printf("\"%s\"\n", tab[i]);
// 		free(tab[i]);  // Libérer chaque mot
// 		i++;
// 	}
// 	free(tab);  // Libérer le tableau de pointeurs
// 	return 0;
// }
