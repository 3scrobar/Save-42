/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/15 19:03:10 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_map	mapcpy;
	t_all	all;

	all.game.mlx = mlx_init();
	if (all.game.mlx == NULL)
		return(ft_putstr_fd("Error load windows\n", 2), 1);
	if (ac != 2)
		return (ft_putstr_fd("Error from Arguments\n", 2), 1);
	if (ft_init_map(&all.map, av[1]) == 1 || ft_init_map(&mapcpy, av[1]) == 1)
		return (1);
	if(ft_init_img(&all) == 1 || ft_total_check(&mapcpy) == 1)
		return (1);
	all.game.win = mlx_new_window(all.game.mlx, all.map.column * all.img.tyle_size,
				all.map.line * all.img.tyle_size, "Bomber-long");
	ft_printf("Map Valide, Launch The Game .....\n");
	draw_map(&all);
	mlx_put_image_to_window(all.game.mlx, all.game.win, all.img.player, all.map.xbegin * all.img.tyle_size, all.map.ybegin * all.img.tyle_size);
	mlx_key_hook(all.game.win, key_press, &all);
	mlx_loop_hook(all.game.win, ft_game_loop, &all);
	mlx_loop(all.game.mlx);
	return (0);
}
int	ft_game_loop(t_all *all)
{
	(void)all;
	return (0);
}

int	check_coll(t_all *all, char *str)
{

	char *down;
	char *up;
	char *left;
	char *right;


	down = "down";
	up = "up";
	left = "left";
	right = "right";

	printf("ton player  x \n %c \n", all->map.map[all->map.ybegin + 1][all->map.xbegin]);
	printf("ton player  ybegin ::: %li \n", all->map.ybegin);
	printf("ton player  xbegin ::: %li \n", all->map.xbegin);


	if ((all->map.map[all->map.ybegin + 1][all->map.xbegin] != '1' ) && str == down)
		return (0);
	else if ((all->map.map[all->map.ybegin - 1][all->map.xbegin] != '1' ) && str == up)
		return (0);
	else if ((all->map.map[all->map.ybegin][all->map.xbegin + 1] != '1' ) && str == right)
		return (0);
	else if ((all->map.map[all->map.ybegin][all->map.xbegin - 1] != '1' ) && str == left)
		return (0);
	return (1);
}

void	gravity(t_all *all)
{	
	if(check_coll(all, "down") != 1)
		all->map.ybegin += 1;
}

int	key_press(int keycode, t_all *all)
{
	mlx_clear_window(all->game.mlx, all->game.win);
	if (keycode == 65307)  // Code de la touche 'Esc'
		mlx_loop_end(all->game.mlx);  // Quitte la boucle d'événements
	else if (keycode == 100&& check_coll(all, "right") != 1)
		all->map.xbegin += 1;
	else if (keycode == 113&& check_coll(all, "left") != 1)
		all->map.xbegin -= 1;
	else if (keycode == 122 && check_coll(all, "up") != 1)
		all->map.ybegin -= 1;
	else if (keycode == 115 && check_coll(all, "down") != 1)
		all->map.ybegin += 1;
	else
	{
		ft_printf("Touche pressée: %d\n", keycode);
	}
	gravity(all);
	draw_map(all);
	mlx_put_image_to_window(all->game.mlx, all->game.win, all->img.player, all->map.xbegin * all->img.tyle_size, all->map.ybegin * all->img.tyle_size);
	return (0);
}
