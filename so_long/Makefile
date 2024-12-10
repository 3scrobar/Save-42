# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 14:34:47 by tle-saut          #+#    #+#              #
#    Updated: 2024/12/10 14:57:56 by tle-saut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz

SRC = map.c so_long.c map_utils.c 

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

OBJDIR = object/
SRCDIR = source/

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): libft/libft.a mlx_linux/libmlx_Linux.a $(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a mlx_linux/libmlx_Linux.a

mlx_linux/libmlx_Linux.a:
	@make all


libft/libft.a:
	@make -C libft

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
