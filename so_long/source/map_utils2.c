/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 15:12:19 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Copie un tableau 2D
char **ft_copy_map(char **src, int rows)
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

void free_tab(char **map)
{
	int	i;
	
	i = 0;
	if (!map)
		return;
	if (map)
		while(map[i])
			free(map[i++]);
	free(map);
}


