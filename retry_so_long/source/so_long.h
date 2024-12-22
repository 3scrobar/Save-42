/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/22 16:45:08 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/source/libft.h"
# include "../minilibx-linux/mlx.h"



typedef struct s_all
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	line;
	size_t	column;
	size_t	player;
	size_t	exit;
	size_t	collectible;
	size_t	xstart;
	size_t	ystart;
}				t_all;

char	**ft_init_tab(int fd);
int	ft_init_map(t_all *map, char *path);
int ft_total_check(int ac, t_all *game, char **av);
int	ft_tablen(char	**tab);
int	ft_give_all_nbpoint(t_all *map);



#endif
