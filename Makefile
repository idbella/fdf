NAME=fdf
FLAGS= -Wall -Wextra -Werror
LIB = -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
INC = -I /usr/local/include -I src/includes
all:$(NAME)
$(NAME):
	make -C src/libft
	cc  -c src/*.c $(FLAGS) $(INC)
	cc -I /usr/local/include $(LIB) $(FLAGS) *.o -o $(NAME)	src/libft/libft.a
clean:
	make -C src/libft/ clean
	rm -rf *.o
fclean: clean
	make -C src/libft/ fclean
	rm -rf $(NAME)
re:fclean 
	make all
