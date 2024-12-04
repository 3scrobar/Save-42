# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 14:34:47 by tle-saut          #+#    #+#              #
#    Updated: 2024/12/04 14:45:16 by tle-saut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

libft/libft.a:
	@make -C libft

$(NAME): libft/libft.a $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a 
