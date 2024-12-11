/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 16:32:08 by tle-saut         ###   ########.fr       */
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
# include "../mlx/mlx.h"

typedef struct s_map
{
	char		**map;
	size_t		player;
	size_t		exit;
	size_t		collectible;
	size_t		column;
	size_t		line;
	size_t		xbegin;
	size_t		ybegin;
	int			check;

}	t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tyle_size;
	void	*sand;
	void	*snow;
	void	*exitdiscover;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int		ft_checkmap_line(t_map *map);
int		ft_parsing(t_map *map);
int		ft_total_check(t_map *map);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_if(char **remaining, char **line);
char	**ft_init_tab(int fd);
int		ft_pos_check(t_map *map);
int		ft_path_check(t_map *map);
int		ft_flood_path(t_map *map, size_t ystart, size_t xstart, char **tab);
int		ft_tablen(char **tab);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
int		key_press(int keycode, void *param);
void	draw_map(void *mlx, void *win,t_map *map, t_data *img);
int		ft_init_map(t_map *map, char *path);
int		ft_init_img(t_vars *mlx, t_data *img);

void	free_tab(char **map);


#endif
