NAME=wolf3d
SRC= core/init.c core/main.c graphic/draw.c graphic/line.c parser/parser.c core/utils.c parser/parse_utils.c world/ray.c core/hooks.c
OBJ=$(SRC:.c=.o)

all: $(NAME)
	make -C libft/
$(NAME):$(OBJ) wolf3d.h keys.h
	make -C graphic/minilib/
	make -C libft/
	gcc $(SRC) libft/libft.a graphic/minilib/libmlx.a -o $(NAME) -framework OpenGL -framework AppKit -lpthread

clean:
		make clean -C libft/
		rm -f $(OBJ)

fclean:	clean
		make fclean -C libft/
		make clean -C graphic/minilib/
		rm -rf $(NAME)

re: fclean all
