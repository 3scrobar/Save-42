/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/20 16:10:04 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/source/libft.h"
# include "../minilibx-linux/mlx.h"



typedef struct s_all
{
	char	**map;
	size_t	player;
	size_t	exit;
	size_t	collectible;
	size_t	column;
	size_t	line;
	size_t	xbegin;
	size_t	ybegin;
	size_t	xplayer;
	size_t	yplayer;
	int		tile_size;
	void	*mlx;
	void	*win;
}				t_all;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		ft_tablen(char **tab);
int		ft_checkmap_line(t_all *map);
int		ft_total_check(char *path);
int		ft_flood_path(t_all *map, size_t ystart, size_t xstart, char **tab);
int		ft_path_check(t_all *map);
int		ft_init_map(t_all *map, char *path);
int		ft_parsing(t_all *map);
int		ft_pos_check(t_all *map);
int		ft_init_img(t_all *all);
char	**ft_init_tab(int fd);
void	draw_map(t_all *all);
void	free_tab(char **map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);



#endif
