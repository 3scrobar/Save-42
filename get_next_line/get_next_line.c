/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:58:12 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/21 13:13:03 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_if(char **newline, char **remaining, char **line, char **temp)
{
	*newline = ft_strchr(*remaining, '\n');
	if (*newline)
	{
		*line = ft_substr(*remaining, 0, *newline - *remaining + 1);
		*temp = ft_strdup(*newline + 1);
		free(*remaining);
		*remaining = *temp;
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
	static char	*remaining = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*temp;
	char		*newline;

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
		ft_if(&newline, &remaining, &line, &temp);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	// Ouvrir le fichier en lecture
// 	fd = open("essai.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erreur lors de l'ouverture du fichier");
// 		return (1);
// 	}

// 	// Lire et afficher chaque ligne
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line); // N'oubliez pas de libérer la mémoire allouée par get_next_line
// 	}

// 	// Fermer le fichier
// 	close(fd);
// 	return (0);
// }
