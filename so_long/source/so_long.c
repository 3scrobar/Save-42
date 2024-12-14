/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/13 18:26:52 by groot            ###   ########.fr       */
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


	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return(ft_putstr_fd("Error load windows\n", 2), 1);
	if (ac != 2)
		return (ft_putstr_fd("Error from Arguments\n", 2), 1);
	if (ft_init_map(&map, av[1]) == 1 || ft_init_map(&mapcpy, av[1]) == 1)
		return (1);
	else if(ft_init_img(&img, &game) == 1 || ft_total_check(&mapcpy) == 1)
		return (1);
	game.win = mlx_new_window(game.mlx, map.column * img.tyle_size,
				map.line * img.tyle_size, "Bomber-long");
	ft_printf("Map Valide, Launch The Game .....\n");
	all.map = &map;
	all.game = &game;
	all.img = &img;
	draw_map(all.game, all.map, all.img);
	mlx_put_image_to_window(game.mlx, game.win, img.player, map.xbegin * img.tyle_size, map.ybegin * img.tyle_size);
	mlx_key_hook(game.win, key_press, game.mlx);
	mlx_loop_hook(game.win, ft_game_loop, &all);
	mlx_loop(game.mlx);



	return (0);
	
}
int	ft_game_loop(t_all *all)
{
	draw_map(all->game, all->map, all->img);
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
