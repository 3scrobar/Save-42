#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return NULL;
}

char *ft_strdup(const char *s1)
{
    int i = 0;
    char *copy;
    
    while (s1[i])
        i++;
    copy = (char *)malloc(i + 1);
    if (!copy)
        return NULL;
    for (int j = 0; j <= i; j++)
        copy[j] = s1[j];
    return copy;
}

char *ft_strjoin(char *s1, char *s2)
{
    int len1 = 0, len2 = 0;
    char *new_str;

    while (s1 && s1[len1])
        len1++;
    while (s2[len2])
        len2++;
    
    new_str = (char *)malloc(len1 + len2 + 1);
    if (!new_str)
        return NULL;
    
    for (int i = 0; i < len1; i++)
        new_str[i] = s1[i];
    for (int j = 0; j < len2; j++)
        new_str[len1 + j] = s2[j];

    new_str[len1 + len2] = '\0';
    free(s1);
    return new_str;
}

char *get_next_line(int fd)
{
    static char *storage;
    char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytes_read, i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    while (!ft_strchr(storage, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        storage = ft_strjoin(storage, buffer);
    }

    if (!storage || !storage[0])
        return NULL;

    while (storage[i] && storage[i] != '\n')
        i++;

    line = (char *)malloc(i + 2);
    for (int j = 0; j <= i; j++)
        line[j] = storage[j];
    line[i + 1] = '\0';

    char *new_storage = ft_strdup(storage + i + 1);
    free(storage);
    storage = new_storage;

    return line;
}

#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd);

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur ouverture fichier");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("Ligne lue: %s", line);
        free(line);
    }

    close(fd);
    return (0);
}
