# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 17:01:24 by tle-saut          #+#    #+#              #
#    Updated: 2024/12/04 14:15:27 by tle-saut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la bibliothèque
NAME = libft.a

# Compilateur et options de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers source et objets
SRC = *.c # Ajoutez tous les fichiers .c nécessaires

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
