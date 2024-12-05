/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:14 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/04 16:36:18 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char ** ft_malloc_tab(int fd)
{
	int len;

	len = 0;
	
}

char ** ft_fill_tab(int fd)
{
	char	**tab;
	int		i;
	
	i = 0;
	tab = NULL;
	while (fd != 0)
	{
		tab[i] = get_next_line(fd);
		i++;
	}
	return (tab);
}
