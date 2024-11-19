/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:52:35 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/19 14:59:27 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *toprint;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	toprint = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (toprint == NULL)
		return (NULL);
	read(fd, toprint, BUFFER_SIZE);
	return (toprint);
}
int main(void)

