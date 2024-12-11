/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 17:24:03 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int ac, char **av)
{
	t_map	map;
	t_vars	game;
	t_data	img;
	t_map	mapcpy;
	t_all	all;

	all.game = &game;
	all.img = &img;
	all.map = &map;
	game.mlx = mlx_init();
	if (ac != 2)
		return (ft_putstr_fd("Error from Arguments\n", 2), 1);
	if (ft_init_map(&all, av[1]) == 1 || ft_init_map(&all, av[1]) == 1)
		return (1);
	else if(ft_init_img(&all) == 1 || ft_total_check(&all) == 1)
		return (1);
	game.win = mlx_new_window(game.mlx, map.column * img.tyle_size,
				map.line * img.tyle_size, "Bomber-long");
	ft_printf("Map Valide, Launch The Game .....\n");

	mlx_key_hook(game.win, key_press, game.mlx);
	mlx_loop_hook(game.win, ft_game_loop, &all);

	mlx_loop(game.mlx);
	return (0);
}
int	ft_game_loop(t_all *all)
{
	ft_game_draw(all);
	return (0);
}
int	ft_game_draw(t_all *all)
{
	draw_map(all->game->mlx, all->game->win, all->map, all->img);
	return (0);
}


int key_press(int keycode, void *param)
{
    if (keycode == 65307)  // Code de la touche 'Esc'
    {
        ft_printf("Touche ESC capturée !\n");
        mlx_loop_end(param);  // Quitte la boucle d'événements
    }
    else
    {
        ft_printf("Touche pressée: %d\n", keycode);
    }
    return (0);
}
