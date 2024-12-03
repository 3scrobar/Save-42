/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/03 14:50:39 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkmap(char *map)
{
	int					cursor;
	static int			player = 0;
	static int			line = 0;
	static int			exit = 0;
	int					collectible;

	collectible = 0;
	cursor = 0;
	while (map[cursor])
	{
		if (map[cursor] != "1" && line ==0)
			return (0);
		else if (map[cursor] == "P")
			player++;
		else if (map[cursor] == "E")
			exit++;
		else if (map[cursor] == "C")
			collectible++;
		cursor++;
	}
	if (player != 1 || exit != 1 || collectible == 0)
		return (0);
}
