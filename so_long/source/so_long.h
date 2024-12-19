/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/19 17:20:42 by tle-saut         ###   ########.fr       */
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
	int		check;
	void	*imgwall;
	void	*imgfont;
	void	*imgexitdiscover;
	void	*imgexitcover;
	void	*imgcollectible;
	void	*imgplayer;
	void	*mlx;
	void	*win;
	void	*imgwind;
	int		keys[256];
}				t_all;

int		ft_init_map(t_all *map, char *path);
int		ft_tablen(char	**tab);
int		ft_checkmap_line(t_all *map);
int		ft_total_check(t_all *map);
int		ft_parsing(t_all *map);
int		ft_pos_check(t_all *map);
int		ft_flood_path(t_all *map, size_t ystart, size_t xstart, char **tab);
int		ft_path_check(t_all *map);
void	free_tab(char **map);
char	**ft_init_tab(int fd);
int		ft_init_img(t_all *all);
void	draw_map(t_all *all);
int		key_press(int keycode, t_all *all);
int		ft_game_loop(t_all *all);
int		ft_game_draw(t_all *all);
int		check_coll(t_all *game, char *str);
void	start_xy(t_all *game);
int		get_tile_at(t_all *game);
int		ft_move(t_all *game);
int 	key_press(int keycode, t_all *data);
int		key_release(int keycode, t_all*data);
void	init_keys(t_all *all);
int close_window(t_all *data);
int keypress(int keycode, t_all *data);


#endif
