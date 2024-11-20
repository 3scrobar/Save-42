/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:52:35 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/20 16:26:18 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char *ft_splits(char **temp)
{
	size_t	i;
	size_t	j;
	char	*final;

	i = 0;
	j = 0;
	while (temp[i] != 10)
		i++;
	final = malloc(sizeof(char) * (i + 1));
	final[i + 1] = 0;
	while (*temp[j + i])
	{
		*temp[j] = *temp[j + i];
		j++;
	}
	return (final);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	unsigned char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s1);
	dest[i + j] = 0;
	return ((char *)dest);
}
char	*get_next_line(int fd)
{
	const char	*finalstr;
	const char	*temp;
	size_t		i;

	i = 0;
	finalstr = malloc(sizeof(char) * BUFFER_SIZE);
	temp = malloc(sizeof(char) * 8000);
	while (read(fd, temp, BUFFER_SIZE) > 0)
	{
		temp = read(fd, temp, BUFFER_SIZE);
		while (temp[i])
		{
			if (temp[i] == 10)
					finalstr = ft_splits(&temp);
			if (ft_strchr(temp, 10) == NULL)
				finalstr = ft_strjoin(finalstr, temp);
			i++;
		}
	}
	return (finalstr);
	
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
