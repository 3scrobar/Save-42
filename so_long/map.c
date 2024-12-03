/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/03 15:03:57 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_parsing(char **map, int *player, int *exit, int *collectible)
{
	int	cursor;

	cursor = 0;
		while (*map[cursor])
	{
		if (*map[0] != '0')
			return (0);
		else if (*map[cursor] == "P")
			*player += 1;
		else if (*map[cursor] == "E")
			*exit += 1;
		else if (*map[cursor] == "C")
			*collectible += 1;
		cursor++;
	}
	return (1);
}

int	ft_checkmap_line(char *map)
{
	int					cursor;
	static int			player = 0;
	static int			line = 0;
	static int			exit = 0;
	int					collectible;

	collectible = 0;
	cursor = 0;
	if (ft_parsing(map, &line, &player, &exit, &collectible) == 0)
		return (write(1, "Error, Map is invalide",22),1);
	if (player != 1 || exit != 1 || collectible == 0)
		return (write(1, "Error, Map is invalide",22),1);
}
