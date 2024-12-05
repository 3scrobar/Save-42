/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/05 14:21:40 by tle-saut         ###   ########.fr       */
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
# include "libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		player;
	int		exit;
	int		collectible;
	int		column;
	int		line;
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
char	**ft_fill_tab(size_t fd);
int		ft_get_tabsize(int fd);


#endif
