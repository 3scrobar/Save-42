/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/03 16:51:12 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parsing(t_map map)
{
	int	i;
	int	j;
	int	len;

	j= 0;
	i = 0;
		while (map.map[i])
		{
			while (map.map[i][j])
			{
				len = ft_strlen(map.map[i]);
				if (map.map[0][j] != '1' || map.map[i][0] != '1'
				 || map.map[i][len - 1] != '1' || map.map[i][0] != '1')
					return (write(1, "Error from map\n", 16),0);
				j++;
			}
			i++;
		}
	return (1);
}

int	ft_checkmap_line(t_map map)
{
	
}
