# Nom de l'exécutable
NAME = push_swap

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Répertoires
SRCDIR = source/
OBJDIR = object/
LIBDIR = libft/

# Fichiers source et objets
SRC = main.c utils_1.c lst_1.c lst_2.c rotate.c swap.c push.c reverse_rotate.c algo.c check.c sort.c
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# Règle principale
all: $(NAME)

# Création de l'exécutable
$(NAME): libft/libft.a $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "$(NAME) compiled successfully!"

# Création des fichiers objets
$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Création du répertoire pour les fichiers objets
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compilation de la libft
libft/libft.a:
	@echo "Building libft..."
	@make -C $(LIBDIR)

# Nettoyage des fichiers objets
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)

# Nettoyage complet
fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

# Récompilation complète
re: fclean all

# Déclaration des règles comme "phony"
.PHONY: all clean fclean re
