/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:19:51 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 14:33:14 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map ft_copy_map(t_map *origin)
{
	t_map final;
	
	final.map = origin->map;
	final.collectible = origin->map;
	final.column = origin->map;
	final.exit = origin->map;
	final.line = origin->map;
	final.player = origin->map;
	final.xbegin = origin->map;
	final.ybegin = origin->map;
	return(final);
}
