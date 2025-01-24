NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

#************************************SOURCE***********************************#
SRC = main.c

#************************************OBJET************************************#
OBJ = $(SRC:%.c=$(OBJDIR)%.o)
OBJDIR = object/
SRCDIR = source/

#************************************COMPIL***********************************#
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): libft/libft.a $(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

#************************************RULES************************************#

libft/libft.a:
	@make -C libft

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
