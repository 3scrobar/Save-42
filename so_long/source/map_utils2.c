/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:39:15 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 11:47:31 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	ft_cpy_map(t_map *map)
{
	t_map	mapcpy;

	mapcpy.map = map->map;
	mapcpy.xbegin = map->xbegin;
	mapcpy.ybegin = map->ybegin;
	mapcpy.column = map->column;
	mapcpy.line = map->line;
	mapcpy.player = map->player;
	mapcpy.collectible = map->collectible;
	mapcpy.exit = map->exit;
	return (mapcpy);
}
