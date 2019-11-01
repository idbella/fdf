# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 06:02:07 by sid-bell          #+#    #+#              #
#    Updated: 2019/11/01 06:37:47 by sid-bell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

FLAGS= -Wall -Wextra -Werror 

MLX=-framework OpenGl -framework AppKit

LIB= -L /usr/local -lmlx src/libft/libft.a

INC= -I/usr/local/include -Isrc/includes

SRC=src/ft_draw.c	src/ft_drawline.c	src/ft_loadmap.c	src/ft_free.c		src/input.c	src/iso.c\
	src/ft_draw_y.c src/ft_draw_x.c		src/ft_color.c		src/ft_putpixel.c	src/main.c

CFLAGS+=$(INC) $(FLAGS)

OBJ=$(SRC:.c=.o)

all: $(LIB) $(NAME) 
	

$(NAME):$(OBJ)
	gcc -I /usr/local/include $(LIB) $(MLX) $(INC) $(FLAGS) $(OBJ) -o $(NAME)	$(LIBFT)

$(LIB):
	make -C src/libft

clean:
	make -C src/libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C src/libft fclean
	rm -rf $(NAME)

re: clean all
