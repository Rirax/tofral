# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/07 16:26:27 by rlechapt          #+#    #+#              #
#    Updated: 2015/01/13 19:34:32 by rlechapt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = \
fractol.c \
mlx_settings.c \
image.c \
mandelbrot.c \
julia.c \
mandelbar.c

EXT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -o $(NAME) $(SRC) -L libft -lft -L/usr/X11/lib -lmlx -lX11 -lXext

clean:
	make clean -C ./libft
	rm -f $(EXT)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
