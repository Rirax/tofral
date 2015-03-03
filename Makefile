# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/07 16:26:27 by rlechapt          #+#    #+#              #
#    Updated: 2015/03/03 11:00:32 by rlechapt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

SRC = \
fractol.c \
mlx_settings.c \
image.c \
mandelbrot.c \
julia.c \
mandelbar.c

OBJ = $(SRC:%.c=%.o)

all: libs $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft -L/usr/lib -lmlx -framework OpenGL -framework AppKit

libs:
	make -C ./libft

%.o: %.c fractol.h
	$(CC) -c -Wall -Wextra -Werror $<

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all
