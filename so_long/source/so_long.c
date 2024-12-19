/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/19 17:11:51 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_all	game;
	t_all	mapcpy;

	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return(ft_putstr_fd("Error load windows\n", 2), 1);
	if (ac != 2)
		return (ft_putstr_fd("Error from Arguments\n", 2), 1);
	if (ft_init_map(&game, av[1]) == 1 || ft_init_map(&mapcpy, av[1]) == 1)
		return (1);
	if(ft_init_img(&game) == 1 || ft_total_check(&mapcpy) == 1)
		return (1);
	game.win = mlx_new_window(game.mlx, game.column * game.tile_size,
				game.line * game.tile_size, "Bomber-long");
	ft_printf("Map Valide, Launch The Game .....\n");
	start_xy(&game);
	init_keys(&game);
	mlx_loop_hook(game.mlx, ft_game_loop, &game);
    mlx_hook(game.win, 2, 1L << 0, key_press, &game);      // Hook pour KeyPress
    mlx_hook(game.win, 3, 1L << 1, key_release, &game);    // Hook pour KeyRelease
	mlx_loop(game.mlx);
	return (0);
}
int	ft_game_loop(t_all *game)
{
	ft_move(game);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->imgplayer, game->xplayer, game->yplayer);
	mlx_do_sync(game->mlx);
	return (0);
}

int	check_coll(t_all *game, char *str)
{

	char *down;
	char *up;
	char *left;
	char *right;


	down = "down";
	up = "up";
	left = "left";
	right = "right";

	if ((game->map[game->y + 1][game->xbegin] != '1' ) && str == down)
		return (0);
	else if ((game->map[game->ybegin - 1][game->xbegin] != '1' ) && str == up)
		return (0);
	else if ((game->map[game->ybegin][game->xbegin + 1] != '1' ) && str == right)
		return (0);
	else if ((game->map[game->ybegin][game->xbegin - 1] != '1' ) && str == left)
		return (0);
	return (1);
}


int	ft_move(t_all *game)
{
	if (game->keys[100] && check_coll(game, "right") != 1)
		game->xplayer += 1;
	if (game->keys[97] && check_coll(game, "left") != 1)
		game->xplayer -= 1;
	if (game->keys[119] && check_coll(game, "up") != 1)
		game->yplayer -= 1;
	if (game->keys[115] && check_coll(game, "down") != 1)
		game->yplayer += 1;
	return (0);
}
