/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/03 16:22:34 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parsing(t_map map)
{
	int	i;
	int	j;

	j= 0;
	i = 0;
		while (map.map[i])
		{
			while (map.map[i][j])
			{
				if (map.map[0][j] != '0')
					return (write(1, "Error from map\n", 16));
				
			}
		}
	return (1);
}

int	ft_checkmap_line(t_map map)
{

}
