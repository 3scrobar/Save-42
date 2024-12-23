/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/23 15:59:13 by tle-saut         ###   ########.fr       */
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

int		ft_tablen(char	**tab);
int		ft_give_all_nbpoint(t_all *map);
int		ft_check_square(t_all *map);
int		ft_give_start_POS(t_all *game);
int		ft_flood_path(t_all *game, size_t y, size_t x);
int		ft_check_after_flood(t_all *game);
char	**ft_init_tab(int fd);
int		ft_init_map(t_all *map, char *path);
void	ft_copy_struct(t_all *game, t_all *cpy);
int ft_total_check(int ac, t_all *game, char **av, t_all *cpy);

#endif
