/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 14:41:53 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Copie un tableau 2D
char **copy_map(char **src, int rows)
{
	char **copy = malloc(sizeof(char *) * (rows + 1)); // +1 pour NULL
	if (!copy)
		return NULL;

	for (int i = 0; i < rows; i++) {
		copy[i] = strdup(src[i]); // Copie chaque ligne
		if (!copy[i]) {
			// Libérer en cas d'erreur
			for (int j = 0; j < i; j++)
				free(copy[j]);
			free(copy);
			return NULL;
		}
	}
	copy[rows] = NULL; // Termine par NULL
	return copy;
}

t_map *copy_t_map(t_map *src)
{
	t_map *copy = malloc(sizeof(t_map));
	if (!copy)
		return NULL;

	*copy = *src; // Copie les champs simples par valeur

	// Copie le tableau 2D
	if (src->map)
		copy->map = copy_map(src->map, src->line);
	else
		copy->map = NULL;

	return copy;
}

void free_t_map(t_map *map)
{
	if (!map)
		return;

	// Libérer le tableau 2D
	if (map->map) {
		for (int i = 0; map->map[i]; i++)
			free(map->map[i]);
		free(map->map);
	}

	free(map);
}


