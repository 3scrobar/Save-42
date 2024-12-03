/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/03 17:08:41 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	char	**map;
	int		player;
	int		exit;
	int		collectible;
}	t_map;

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_checkmap_line(t_map map);
int	ft_parsing(t_map map);
size_t	ft_strlen(const char *s);
int	ft_total_check(t_map *map);
void	ft_init_map(t_map *map);

#endif
