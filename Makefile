# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 06:02:07 by sid-bell          #+#    #+#              #
#    Updated: 2019/11/03 11:54:01 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

FLAGS= #-Wall -Wextra -Werror 

LIBMLX= -L /usr/local -lmlx -framework OpenGl -framework AppKit

LIBFT= src/libft/libft.a

INC= -I/usr/local/include -Isrc/includes

SRC=src/ft_draw.c	src/ft_drawline.c	src/ft_loadmap.c	src/ft_free.c		src/input.c	src/iso.c\
	src/ft_draw_y.c src/ft_draw_x.c		src/ft_color.c		src/ft_putpixel.c	src/main.c

CFLAGS+=$(INC) $(FLAGS)

CC=gcc

OBJ=$(SRC:.c=.o)

all: $(LIBFT) $(NAME) 
	

$(NAME):$(OBJ)
	$(CC) -I /usr/local/include $(LIBFT) $(LIBMLX) $(INC) $(FLAGS) $(OBJ) -o $(NAME)

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