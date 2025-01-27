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
SRC = main.c
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# Règle principale
all: $(NAME)

# Création de l'exécutable
$(NAME): libft/libft.a $(OBJDIR) $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "$(NAME) compiled successfully!"

# Création des fichiers objets
$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation de la libft
libft/libft.a:
	@echo "Building libft..."
	@make -C $(LIBDIR)

# Nettoyage des fichiers objets
clean:
	@echo "Cleaning object files..."
	@rm -fr $(OBJDIR)

# Nettoyage complet
fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

# Récompilation complète
re: fclean all

# Déclaration des règles comme "phony"
.PHONY: all clean fclean re
