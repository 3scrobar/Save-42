/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:52:35 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/19 16:01:51 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *ft_cut(char **pSRC)
{
	size_t	i;
	size_t	j;
	
	char 	*temp;
	
	j = 0;
	temp = "";
	i = 0;
	while (pSRC[i])
	{
		if (pSRC[i] == 92 && pSRC[i + 1] == 'n')
			{
				while (pSRC[i + j])
					{
						temp[j] = pSRC[i + j];
						j++;
					}
				j++;
			}
		i++;
	}
	pSRC[]
	return (temp);
}
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
	dest[i + j] = 0;
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
	//stack in temp temp and stack in the final temp
	while (i > 0)
	{
		i = read(fd, strtemp, BUFFER_SIZE);	
		toprint = ft_stack(strtemp, toprint);
	}
	//cut and manage into final temp
	toprint = ft_cut(&strtemp);
	//check if the ready is finiched
	//return final temp
	
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
