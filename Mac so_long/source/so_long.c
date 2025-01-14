/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/14 16:57:02 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define RIGHT 2
#define LEFT 0
#define UP 13
#define DOWN 1
#define SPEED 2

int	main(int ac, char **av)
{
	t_all	game;
	t_all	cpy;

	game.mlx = mlx_init();
	if (ft_total_check(ac, &game, av, &cpy) != 0 || game.mlx == NULL)
		return (1);
	ft_printf("Check for the flood\n");
	if (ft_flood_path(&cpy, cpy.ystart, cpy.xstart) != 0 
		|| ft_check_after_flood(&cpy) != 0 || ft_init_img(&game) != 0)
		return (ft_putstr_fd("Error from Path\n", 2), 1);
	game.win = mlx_new_window(game.mlx, game.column * 64, (game.line + 1) * 64, "so_long");
	game.xstart = game.xstart * game.tile_size;
	game.ystart = game.ystart * game.tile_size;
	mlx_hook(game.win, 17, 1L << 17, ft_close, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_handle_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_handle_key_release, &game);

	mlx_loop_hook(game.mlx, ft_game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
char	**ft_init_tab(int fd)
{
	int		a;
	char	buffer[BUFFER_SIZE + 1];
	char	**tab;
	char	*line;

	line = NULL;
	while (1)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a < 1)
			break ;
		if (line == NULL)
			line = ft_strdup(buffer);
		else
			line = ft_strjoinfree(&line, buffer);
	}
	tab = ft_split(line, '\n');
	free(line);
	return (tab);
}
int	ft_init_map(t_all *map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error from file reading\n", 2), 1);
	map->map = ft_init_tab(fd);
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->column = 0;
	map->line = 0;

	close(fd);
	return (0);
}
int ft_total_check(int ac, t_all *game, char **av, t_all *cpy)
{
	if (ac != 2)
		return (ft_putstr_fd("Wrong Arguments\n", 2), 1);
	if (ft_init_map(game, av[1]) != 0 || ft_init_map(cpy, av[1]) != 0)
		return (ft_putstr_fd("Problem from Map init\n", 2), 1);
	if (ft_give_all_nbpoint(game) != 0 || ft_check_square(game) != 0 
		|| ft_give_all_nbpoint(cpy) != 0 || ft_check_square(cpy) != 0)
		return (ft_putstr_fd("Error from map design\n", 2), 1);
	if (game->player != 1)
		return (ft_putstr_fd("Problem from Start POS\n", 2), 1);
	if (game->exit != 1)
		return (ft_putstr_fd("Problem from Exit POS\n", 2), 1);
	if (game->collectible == 0)
		return (ft_putstr_fd("No Collectible\n", 2), 1);
	ft_give_start_POS(game);
	ft_give_start_POS(cpy);
	if(ft_check_border(cpy) != 0)
		return (1);
	if(ft_flood_path(cpy, cpy->ystart, cpy->xstart) != 0 
		|| ft_check_after_flood(cpy) != 0)
		return (ft_putstr_fd("Error from Path\n", 2), 1);
	game->xvelocity = 0;
	game->yvelocity = 0;
	return (ft_printf("Everything is Good, Launch the Game ...\n",0), 0);
}
int	ft_tablen(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i - 1);
}
int	ft_give_all_nbpoint(t_all *map)
{
	int	i;
	int	j;

	i = 0;
	map->line = ft_tablen(map->map);
	map->column = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != map->column)
			return (ft_putstr_fd("Line is not the same size\n", 2), 1);
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->player += 1;
			else if (map->map[i][j] == 'E')
				map->exit += 1;
			else if (map->map[i][j] == 'C')
				map->collectible += 1;
			j++;
		}
		i++;
	}
	return (0);
}
int	ft_check_square(t_all *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (j != map->column)
			return (ft_putstr_fd("Line as not the same size\n", 2), 1);
		i++;
	}
	return (0);
}
int	ft_give_start_POS(t_all *game)
{
	game->mvleft = 0;
	game->mvright = 0;
	game->ystart = 0;
	game->is_jumpimg = 0;
	game->nb_move = 0;
	game->mvleft = 0;
	game->mvright = 0;
	game->enemyvelocity = -2;
	game->xenemy = (game->column - 2) * 64;
	game->yenemy = (game->line - 1) * 64;
	game->destroyenemy = 0;
	game->hp = 5;
	while (game->map[game->ystart])
	{
		game->xstart = 0;
		while (game->map[game->ystart][game->xstart])
		{
			if (game->map[game->ystart][game->xstart] == 'P')
				return (0);
			game->xstart++;
		}
		game->ystart++;
	}
	return (ft_putstr_fd("Starting POS Missing\n", 2), 1);
}
int	ft_flood_path(t_all *game, size_t ystart, size_t xstart)
{
	if (game->map[ystart][xstart] == '1')
		return (0);

	if (game->map[ystart][xstart] != '1')
		game->map[ystart][xstart] = '1';
	ft_flood_path(game, ystart + 1, xstart);
	ft_flood_path(game, ystart - 1, xstart);
	ft_flood_path(game, ystart, xstart + 1);
	ft_flood_path(game, ystart, xstart - 1);
	return (0);
}
int	ft_check_after_flood(t_all *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1')
				return (ft_putstr_fd("Path is invalid\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}
int	ft_check_border(t_all *map)
{
	int	i;

	i = 0;
	while (i < map->column)
	{
		if (map->map[0][i] != '1' || map->map[map->line][i] != '1')
			return (ft_putstr_fd("Error from map border\n", 2), 1);
		i++;
	}
	i = 0;
	while (i <= map->line)
	{
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			return (ft_putstr_fd("Error from map border\n", 2), 1);
		i++;
	}
	return (0);
}


int	ft_game_loop(t_all *game)
{
	
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	ft_velocity_apply(game);
	ft_collision_check(game);
	ft_security_check(game);
	game->gravity = 1;
	mlx_string_put(game->mlx, game->win, 880, 20, 0xFF0000, "Nbr PDV : ");
	mlx_string_put(game->mlx, game->win, 980, 20, 0xFF0000, ft_itoa(game->hp));

	ft_col_enemy(game);
	ft_manage_enemy(game);
	if (game->xvelocity < 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgplayerleft, game->xstart, game->ystart);
	if (game->xvelocity > 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgplayerright, game->xstart, game->ystart);
	if (game->xvelocity == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgplayercenter, game->xstart, game->ystart);
	if (game->enemyvelocity < 0 && game->destroyenemy == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgenemyleft, game->xenemy, game->yenemy);
	if (game->enemyvelocity > 0 && game->destroyenemy == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->imgenemyright, game->xenemy, game->yenemy);
	if(game->hp == 0)
			ft_close(game);
	
	return (0);
}
int	ft_close(t_all *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

//draw map
int draw_map(t_all *all)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == '0')
				mlx_put_image_to_window(all->mlx, all->win, all->imgfont, x * all->tile_size, y * all->tile_size);
			else if (all->map[y][x] == '1')
				mlx_put_image_to_window(all->mlx, all->win, all->imgwall, x * all->tile_size, y * all->tile_size);
			else if (all->map[y][x] == 'E' && all->collectible == 0)
				mlx_put_image_to_window(all->mlx, all->win, all->imgexit, x * all->tile_size, y * all->tile_size);
			else if (all->map[y][x] == 'E' && all->collectible != 0)
				mlx_put_image_to_window(all->mlx, all->win, all->exitcover, x * all->tile_size, y * all->tile_size);
			else if (all->map[y][x] == 'C')
				mlx_put_image_to_window(all->mlx, all->win, all->imgcollectible, x * all->tile_size, y * all->tile_size);
			x++;
		}
		y++;
	}
	return (0);
}
 int	ft_init_img(t_all *all)
{
	all->imgfont = mlx_xpm_file_to_image(all->mlx, "img/font.xpm", &all->tile_size, &all->tile_size);
	all->imgwall = mlx_xpm_file_to_image(all->mlx, "img/wall.xpm", &all->tile_size, &all->tile_size);
	all->imgexit = mlx_xpm_file_to_image(all->mlx, "img/window.xpm", &all->tile_size, &all->tile_size);
	all->exitcover = mlx_xpm_file_to_image(all->mlx, "img/door_closedMid.xpm", &all->tile_size, &all->tile_size);
	all->imgcollectible = mlx_xpm_file_to_image(all->mlx, "img/coinGold.xpm", &all->tile_size, &all->tile_size);
	all->imgplayerright = mlx_xpm_file_to_image(all->mlx, "img/playerright.xpm", &all->tile_size, &all->tile_size);
	all->imgplayerleft = mlx_xpm_file_to_image(all->mlx, "img/playerleft.xpm", &all->tile_size, &all->tile_size);
	all->imgplayercenter = mlx_xpm_file_to_image(all->mlx, "img/playercenter.xpm", &all->tile_size, &all->tile_size);
	all->imgenemyright = mlx_xpm_file_to_image(all->mlx, "img/enemyright.xpm", &all->tile_size, &all->tile_size);
	all->imgenemyleft = mlx_xpm_file_to_image(all->mlx, "img/enemyleft.xpm", &all->tile_size, &all->tile_size);
	if (all->imgfont == NULL || all->imgwall == NULL || all->imgexit == NULL || all->imgcollectible == NULL 
		|| all->imgplayerright == NULL || all->imgplayerleft == NULL)
		return(ft_putstr_fd("Error load an img\n", 2), 1);
	return(0);
}
int ft_collision_check(t_all *all)
{
	if (ft_colision_right(all) == 1)
	{
		all->xvelocity = 0;
	}
	if (ft_colision_left(all) == 1)
	{
		all->xvelocity = 0;
	}
	if (ft_colision_up(all) == 1)
	{
		all->yvelocity = 0;
	}
	if (ft_colision_down(all) == 1)
	{
		all->yvelocity = 0;
		all->ystart= (all->ystart / all->tile_size) * all->tile_size;
		all->is_jumpimg = 0;
	}
	return(0);
}

int ft_colision_right(t_all *all)
{
	int right;

    right  = (all->xstart + 58) / all->tile_size;
	if (all->map[((all->ystart + 32) / all->tile_size)][right] == '1')
		return(1);
	return(0);
}
int ft_colision_left(t_all *all)
{
	int left;

	left   = ((all->xstart + 10)/ all->tile_size);
	if (all->map[(all->ystart + 48) / all->tile_size][left] == '1')
		return(1);
	return(0);
}
int ft_colision_up(t_all *all)
{
	int top;

	top    = ((all->ystart + 31)/ all->tile_size);
	if (all->map[top][(all->xstart + 32) / all->tile_size] == '1' || top == 0)
		return(1);
	return(0);
}
int ft_colision_down(t_all *all)
{
	int bottom;

	bottom = ((all->ystart + 65) / 64 );
	if (all->map[bottom][(all->xstart + 32) / all->tile_size] == '1')
		return(1);
	return(0);
}
void 	ft_velocity_apply(t_all *all)
{

	if(all->xvelocity < 0)
		all->xvelocity += 1;
	if(all->xvelocity > 0)
		all->xvelocity -= 1;
	if(all->yvelocity > 20)
		all->yvelocity = 20;
	if(all->yvelocity < -32)
		all->yvelocity = -32;
	if(all->xvelocity > 20)
		all->xvelocity = 20;
	if(all->xvelocity < -20)
		all->xvelocity = -20;
	if(ft_colision_down(all) == 0)
		all->yvelocity += 5;
	if(all->mvright == 1 && ft_colision_right(all) == 0)
		all->xvelocity += SPEED;
	if(all->mvleft == 1 && ft_colision_left(all) == 0)
		all->xvelocity -= SPEED;
	if(all->xvelocity < 0)
		all->nb_move -= all->xvelocity;
	else
		all->nb_move += all->xvelocity;
	all->xstart += all->xvelocity;
	all->ystart += all->yvelocity;
}
void	ft_security_check(t_all *all)
{
	if (((all->xstart - 1) / all->tile_size) < 1)
		all->xstart = 1 * all->tile_size;
	if ((all->ystart) < 31)
	{
		all->ystart = 32 ;
	}
	if ((all->xstart + 1) > ((all->column - 2) * 64))
		all->xstart = (all->column - 2 )* 64;
	if (all->ystart > (all->line - 1) * 64)
		all->ystart = (all->line - 1) * 64;
	if(all->map[((all->ystart)/ all->tile_size)][((all->xstart + 32) / all->tile_size)] == 'C')
	{
		all->map[((all->ystart) / all->tile_size)][((all->xstart + 32) / all->tile_size)] = '0';
		all->collectible -= 1;
	}
	if(all->map[((all->ystart) / all->tile_size)][((all->xstart + 32) / all->tile_size)] == 'E' && all->collectible == 0)
	{
		mlx_destroy_window(all->mlx, all->win);
		ft_printf("You Win in %d move\n", all->nb_move / 64);
		exit(0);
	}
}
int 	ft_handle_key_press(int keycode, t_all *all)
{
	if(keycode == 2)
	{
		all->mvright = 1;
		all->mvleft = 0;
	}
	if(keycode == 0)
	{
		all->mvleft = 1;
		all->mvright = 0;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	if(keycode == 13 && ft_colision_up(all) == 0 && all->is_jumpimg < 2)
	{
		all->yvelocity = -40;
		all->is_jumpimg += 1;
	}
	//ft_printf("Keycode : %d\n", keycode);
	return (0);
}
int	ft_handle_key_release(int keycode, t_all *all)
{
	if(keycode == RIGHT)
	{
		all->mvright = 0;
	}
	if(keycode == LEFT)
	{
		all->mvleft = 0;
	}
	return (0);
}
void	ft_manage_enemy(t_all *all)
{
	if (all->enemyvelocity < 0 && all->map[(all->yenemy - 32)/ 64][((all->xenemy )/ 64) - 1] == '1')
		all->enemyvelocity = 4;
	if (all->enemyvelocity > 0 && all->map[(all->yenemy - 32)/ 64][((all->xenemy)/ 64) + 1] == '1')
		all->enemyvelocity = -4;
	all->xenemy += all->enemyvelocity;
	
	if (((all->xstart < all->xenemy + 44 && all->xstart + 44 > all->xenemy) || (all->xstart + 44 < all->xenemy && all->xstart > all->xenemy + 44)) && all->ystart + 64 == all->yenemy + 64 && all->destroyenemy == 0)
		{
			all->hp -= 1;
		}
	
}
void	ft_col_enemy(t_all *all)
{
	if(all->xenemy < all->xstart + 32 && all->xenemy + 64 > all->xstart + 32 && all->yenemy == all->ystart + 32)
	{
		all->destroyenemy = 1;
		mlx_destroy_image(all->mlx, all->imgenemyleft);
		mlx_destroy_image(all->mlx, all->imgenemyright);
		all->xenemy = 0;
		all->yenemy = 0;
		ft_putstr_fd("Enemy Destroyed\n", 1);
	}
}
void	ft_get_enemy_pos(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'E')
			{
				all->xenemy = j * 64;
				all->yenemy = i * 64;
			}
			j++;
		}
		i++;
	}
}
