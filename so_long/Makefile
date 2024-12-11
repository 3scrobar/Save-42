# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 14:34:47 by tle-saut          #+#    #+#              #
#    Updated: 2024/12/11 14:20:05 by tle-saut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC = map.c so_long.c map_utils.c map_utils2.c

OBJ = $(SRC:%.c=$(OBJDIR)%.o)
OBJDIR = object/
SRCDIR = source/

MLX_NAME	= libmlx.a
MLX_FLAGS	= -l mlx -l Xext -l X11
MLX_DIR	= ./mlx/

LIBSX		=	$(addprefix $(MLX_DIR),$(MLX_NAME))

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): libft/libft.a mlx/libmlx_Linux.a $(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a mlx/libmlx_Linux.a -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -lm

mlx/libmlx_Linux.a:
	@make all


libft/libft.a:
	@make -C libft

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
