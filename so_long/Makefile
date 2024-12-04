# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 14:34:47 by tle-saut          #+#    #+#              #
#    Updated: 2024/12/04 14:56:32 by tle-saut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = map.c main.c

OBJ = $(SRC:.c=.o)


libft/libft.a:
	@make -C libft

$(NAME): libft/libft.a $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a 

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
