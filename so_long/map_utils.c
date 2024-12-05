/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:14 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/05 14:00:01 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_tabsize(int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	int		i;
	int		cpt;

	cpt = 0;
	i = 0;
	while (1)
	{
		line = read(fd, buffer, BUFFER_SIZE);
		if (line == NULL)
			break ;
	}
	while (line[i])
	{
		if (line[i] == '\n')
			cpt++;
	}
	return (cpt);
}

char ** ft_fill_tab(int fd)
{
	char	**tab;
	int		i;
	char	*temp;
	
	i = 0;
	tab = malloc(sizeof(char *) * (ft_get_tabsize(fd) + 1));
	while (fd > 0)
	{
		temp = get_next_line(fd);
		tab[i] = malloc(sizeof(char) * ft_strlen(temp) + 1);
		tab[i] = temp;
		i++;
	}
	return (tab);
}
