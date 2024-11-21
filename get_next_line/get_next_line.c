/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:58:12 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/21 13:55:24 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_if(char **remaining, char **line)
{
	char		newline;

	newline = ft_strchr(*remaining, '\n');
	if (newline)
	{
		*line = ft_substr(*remaining, 0, newline - *remaining + 1);
		*remaining = ft_strdup(newline + 1);
	}
	else
	{
		*line = ft_strdup(*remaining);
		free(*remaining);
		*remaining = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	static int	bol;

	if (bol != 0)
	{
		remaining = NULL;
		bol = 0;
	}
	line = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = 0; 
		if (remaining)
			remaining = ft_strjoin(&remaining, buffer);
		else
			remaining = ft_strdup(buffer);
		if (ft_strchr(remaining, '\n'))
			break ;
	}
	if (remaining)
		ft_if(&remaining, &line);
	return (line);
}


