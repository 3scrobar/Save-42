/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/23 16:06:14 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_all	game;
	t_all	cpy;

	game.mlx = mlx_init();
	if (ft_total_check(ac, &game, av, &cpy) != 0 || game.mlx == NULL)
		return (1);
	if (ft_flood_path(&cpy, cpy.ystart, cpy.xstart) != 0 
		|| ft_check_after_flood(&cpy) != 0)
		return (ft_putstr_fd("Error from Path\n", 2), 1);
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
	(void)game;
	if (ac != 2)
		return (ft_putstr_fd("Wrong Arguments\n", 2), 1);
	if (ft_init_map(game, av[1]) != 0)
		return (ft_putstr_fd("Problem from Map init\n", 2), 1);
	if (ft_give_all_nbpoint(game) != 0 || ft_check_square(game) != 0)
		return (ft_putstr_fd("Error from map design\n", 2), 1);
	if (game->player != 1)
		return (ft_putstr_fd("Problem from Start POS\n", 2), 1);
	if (game->exit != 1)
		return (ft_putstr_fd("Problem from Exit POS\n", 2), 1);
	if (game->collectible == 0)
		return (ft_putstr_fd("No Collectible\n", 2), 1);
	ft_give_start_POS(game);
	ft_copy_struct(game, cpy);
	if(ft_flood_path(cpy, cpy->ystart, cpy->xstart) != 0 
		|| ft_check_after_flood(cpy) != 0)
		return (ft_putstr_fd("Error from Path\n", 2), 1);
	return (ft_printf("Everything is Good, Launch the Game ...\n",0));
}
void	ft_copy_struct(t_all *game, t_all *cpy)
{
	cpy->mlx = game->mlx;
	cpy->win = game->win;
	cpy->map = game->map;
	cpy->line = game->line;
	cpy->column = game->column;
	cpy->player = game->player;
	cpy->exit = game->exit;
	cpy->collectible = game->collectible;
	cpy->xstart = game->xstart;
	cpy->ystart = game->ystart;
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
		if (ft_strlen(map->map[i]) != map->column)
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
	size_t	i;
	size_t	j;

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
	if (game->map[ystart][xstart] == '0' || game->map[ystart][xstart] == 'P' ||
		game->map[ystart][xstart] == 'E' || game->map[ystart][xstart] == 'C')
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

