/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:44 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/03 14:44:48 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkmap(char *map)
{
	int			cursor;
	static int	line;
	int			player;
	int			exit;
	int			collectible;

	player = 0;
	exit = 0;
	collectible = 0;
	line = 0;
	cursor = 0;
	while (map[cursor])
	{
		if (map[cursor] != "1" && line ==0)
			return (0);
		else if (map[cursor])
		cursor++;
	}
	line++;
}
