# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 06:02:07 by sid-bell          #+#    #+#              #
#    Updated: 2020/01/02 21:22:43 by ktbatou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

FLAGS= -Wall -Wextra -Werror 

LIBMLX= -L /usr/local -lmlx -framework OpenGl -framework AppKit

LIBFT= src/libft/libft.a

HEADER= fdf.h

HINC = src/includes/fdf.h

INC= -I/usr/local/include -Isrc/includes -Isrc/libft

SRC=src/ft_draw.c	src/ft_drawline.c	src/ft_loadmap.c	src/ft_free.c		src/input.c	src/iso.c\
	src/ft_draw_y.c src/ft_draw_x.c		src/ft_color.c		src/ft_putpixel.c	src/main.c src/get_color.c

CFLAGS+=$(INC) $(FLAGS)

CC=gcc

OBJ=$(SRC:.c=.o)

all: $(LIBFT)  $(NAME) 

$(NAME): $(HINC) $(OBJ)
	gcc -I /usr/local/include $(LIBFT) $(LIBMLX) $(INC) $(FLAGS) $(OBJ) -o $(NAME)

$(LIBFT):
	make -C src/libft

clean:
	make -C src/libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C src/libft fclean
	rm -rf $(NAME)

re: clean all
test:
	echo $(CFLAGS)