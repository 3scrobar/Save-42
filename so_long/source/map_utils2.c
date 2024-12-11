/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 15:02:59 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Copie un tableau 2D
char **copy_map(char **src, int rows)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	char **copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return NULL;

	while(i < rows)
	{
		copy[i] = strdup(src[i]);
		if (!copy[i])
		{
			while(j++ < i)
				free(copy[j]);
			free(copy);
			return NULL;
		}
		i++;
	}
	copy[rows] = NULL;
	return copy;
}

t_map *copy_t_map(t_map *src)
{
	t_map *copy = malloc(sizeof(t_map));
	if (!copy)
		return NULL;

	*copy = *src;

	if (src->map)
		copy->map = copy_map(src->map, src->line);
	else
		copy->map = NULL;
	return copy;
}

void free_t_map(t_map *map)
{
	int	i;
	
	i = 0;
	if (!map)
		return;
	if (map->map)
	{
		whil(int i = 0; map->map[i]; i++)
			free(map->map[i]);
		free(map->map);
	}

	free(map);
}


