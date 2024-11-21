/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:58:12 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/21 14:45:49 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_if(char **remaining, char **line)
{
	char	*temp;
	char	*newline;

	newline = ft_strchr(*remaining, '\n');
	if (newline)
	{
		*line = ft_substr(*remaining, 0, newline - *remaining + 1);
		temp = ft_strdup(newline + 1);
		free(*remaining);
		*remaining = temp;
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

	line = NULL;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = 0;
		if (remaining)
			remaining = ft_strjoin(&remaining, buffer);
		else
			remaining = ft_strdup(buffer);
		if (ft_strchr(remaining, '\n'))
			break ;
		else if (bytes_read == 0)
			remaining[ft_strlen(remaining) + 1] = "\n";
	}
	if (remaining)
		ft_if(&remaining, &line);
	return (line);
}
int main(void)
{
    int fd;
    char *line;

    // Ouvrir le fichier en lecture
    fd = open("essai.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return (1);
    }

    // Lire et afficher chaque ligne
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Fermer le fichier
    close(fd);
    return (0);
}
