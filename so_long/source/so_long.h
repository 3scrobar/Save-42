/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:52 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/16 15:14:16 by tle-saut         ###   ########.fr       */
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
	int		check;
	int		tile_size;
	void	*imgwall;
	void	*imgfont;
	void	*imgexitdiscover;
	void	*imgexitcover;
	void	*imgcollectible;
	void	*imgplayer;
	void	*mlx;
	void	*win;
}				t_all;





#endif
