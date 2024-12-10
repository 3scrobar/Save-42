/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/10 14:49:14 by tle-saut         ###   ########.fr       */
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
# include "../mlx_linux/mlx.h"

typedef struct s_map
{
	char		**map;
	int			player;
	int			exit;
	int			collectible;
	size_t		column;
	size_t		line;
	int			xbegin;
	int			ybegin;
}	t_map;

int		ft_checkmap_line(t_map *map);
int		ft_parsing(t_map *map);
int		ft_total_check(t_map *map);
int		ft_init_map(t_map *map, char *path);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_if(char **remaining, char **line);
char	**ft_init_tab(int fd);
int		ft_pos_check(t_map *map);
int		ft_path_check(t_map *map);
int		ft_flood_path(t_map *map, size_t ystart, size_t xstart);
int		ft_tablen(char **tab);

#endif
