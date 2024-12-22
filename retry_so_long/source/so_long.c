/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groot <groot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/22 16:42:30 by groot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_all	game;
	(void)av;
	game.mlx = mlx_init();
	if (ft_total_check(ac, &game, av) || game.mlx == NULL)
		return (1);
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
	return (0);
}
int ft_total_check(int ac, t_all *game, char **av)
{
	(void)game;
	if (ac != 2)
		return (ft_putstr_fd("Wrong Arguments\n", 2), 1);
	if (ft_init_map(game, av[1]) != 0)
		return (ft_putstr_fd("Problem from Map init\n", 2), 1);

	return (ft_printf("Everything is Good, Launch the Game ...\n",0));
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

