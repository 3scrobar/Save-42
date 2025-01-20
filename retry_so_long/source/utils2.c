/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:35:59 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/20 18:54:04 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fps(t_all *all)
{
	if (all->counttimer >= 1000)
		{
			ft_game_loop(all);
			all->counttimer = 0;
		}
	else if (all->counttimer < 1000)
	{
		all->counttimer++;
	}
	return (0);
}

void	ft_actualise_image(t_all *all, int exit)
{
	mlx_destroy_image(all->mlx, all->imgcollectible);
	mlx_destroy_image(all->mlx, all->imgenemyleft);
	mlx_destroy_image(all->mlx, all->imgenemyright);
	mlx_destroy_image(all->mlx, all->imgexit);
	mlx_destroy_image(all->mlx, all->imgfont);
	mlx_destroy_image(all->mlx, all->imgplayercenter);
	mlx_destroy_image(all->mlx, all->imgplayerleft);
	mlx_destroy_image(all->mlx, all->imgplayerright);
	mlx_destroy_image(all->mlx, all->imgwall);
	if (exit == 0)
		ft_init_img(all);
}

char **	ft_copy_map(char **map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error from file reading\n", 2), NULL);
	map = ft_init_tab(fd);
	close(fd);
	return (map);
}
void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (i <= ft_tablen(tab))
	{
		free(tab[i]);
	}
	free(tab);
}