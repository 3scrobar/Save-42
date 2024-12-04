# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 17:01:24 by tle-saut          #+#    #+#              #
#    Updated: 2024/12/04 15:18:35 by tle-saut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la bibliothèque
NAME = libft.a

# Compilateur et options de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers source et objets
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_lstadd_back.c get_next_line_utils.c get_next_line.c \
		ft_check.c ft_printf_unsnbr.c ft_printf.c ft_printfchar.c \
		ft_printfnum_base_maj.c ft_printfnumb_base_min.c ft_printfnumb.c \
		ft_printpointer.c ft_printstr.c # Ajoutez tous les fichiers .c nécessaires

OBJ = $(SRC:.c=.o)

# Règle par défaut (target par défaut si on lance `make` sans argument)
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ) $(SRCBONUS:.c=.o)

# Nettoyage complet (fichiers objets + bibliothèque)
fclean: clean
	rm -f $(NAME)

# Recompiler entièrement la bibliothèque
re: fclean all

#éviter que le nomde règle comme "clean" soient interprétés comme des fichiers
.PHONY: all clean fclean re
