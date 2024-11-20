#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i = 0;
	size_t	j = 0;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	dest[i + j] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*remaining = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*temp;

	line = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = 0; 
		if (remaining)
		{
			temp = ft_strjoin(remaining, buffer);
			free(remaining);
			remaining = temp;
		}
		else
			remaining = ft_strdup(buffer);
		// Si un '\n' est trouvé, on sépare la ligne
		if (ft_strchr(remaining, '\n'))
			break ;
	}
	// Si on a lu quelque chose ou si la chaîne n'est pas vide
	if (remaining)
	{
		// Chercher le premier '\n' ou la fin de la chaîne
		char *newline = ft_strchr(remaining, '\n');
		if (newline)
		{
			// Créer la ligne à partir du début jusqu'à '\n'
			line = ft_substr(remaining, 0, newline - remaining + 1);
			// Sauvegarder le reste dans `remaining`
			temp = ft_strdup(newline + 1);
			free(remaining);
			remaining = temp;
		}
		else
		{
			// Si il n'y a pas de '\n', la ligne entière est `remaining`
			line = ft_strdup(remaining);
			free(remaining);
			remaining = NULL;
		}
	}
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
		free(line); // N'oubliez pas de libérer la mémoire allouée par get_next_line
	}

	// Fermer le fichier
	close(fd);
	return (0);
}
