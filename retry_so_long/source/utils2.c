/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:35:59 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/20 17:03:47 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fps(t_all *all)
{
	if (all->counttimer >= 1500)
		{
			ft_game_loop(all);
			all->counttimer = 0;
		}
	else if (all->counttimer < 1500)
	{
		all->counttimer++;
	}
	return (0);
}

void	ft_actualise_image(t_all *all)
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
	ft_init_img(all);
}