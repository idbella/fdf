NAME=fdf
FLAGS= -Wall -Wextra -Werror
LIB = -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
INC = -I /usr/local/include -I src/includes
SRC = src/ft_draw.c src/ft_drawline.c src/ft_loadmap.c src/input.c src/main.c src/ft_free.c src/iso.c\
	src/ft_draw_y.c src/ft_draw_x.c src/ft_color.c src/ft_putpixel.c
OBJ = ft_draw.o ft_drawline.o ft_loadmap.o input.o main.o ft_free.o iso.o ft_draw_y.o ft_draw_x.o ft_color.o ft_putpixel.o
LIBFT = src/libft/libft.a

all:$(NAME)

$(NAME):
	make -C src/libft/
	cc  -c $(SRC) $(FLAGS) $(INC)
	cc -I /usr/local/include $(LIB) $(FLAGS) $(OBJ) -o $(NAME)	$(LIBFT)

clean:
	make -C src/libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C src/libft/ fclean
	rm -rf $(NAME)

re:fclean
	make all

test:
	cc -I /usr/local/include $(LIB) $(FLAGS) main.c -o $(NAME)	$(LIBFT)