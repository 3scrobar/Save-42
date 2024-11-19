/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:52:35 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/19 15:41:43 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_stack(char *src, char *dest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while(dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char *strtemp;
	static char *toprint;
	size_t		i;
	
	if (fd == 0 || BUFFER_SIZE < 0)
		return (NULL);
	//read if everything is good
	//stack in temp str
	while (i > 0)
	{
		i = read(fd, strtemp, BUFFER_SIZE);	
		toprint = ft_stack(strtemp, )
	}
	//cut and manage into final str
	//check if the ready is finiched
	//return final str
	
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
		printf("%s\n", line);
		free(line); // N'oubliez pas de libérer la mémoire allouée par get_next_line
	}

	// Fermer le fichier
	close(fd);
	return (0);
}
