NAME=wolf3d
SRC= core/init.c core/main.c graphic/draw.c graphic/line.c graphic/utils.c parser/parser.c core/utils.c parser/parse_utils.c world/ray.c core/hooks.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) wolf3d.h
	make -C graphic/minilib/
	make -C libft/
	gcc $(SRC) libft/libft.a graphic/minilib/libmlx.a -o $(NAME) -g -framework OpenGL -framework AppKit

clean:
		make clean -C libft/
		rm -f $(OBJ)

fclean:	clean
		make fclean -C libft/
		make clean -C graphic/minilib/
		rm -rf $(NAME)

re: fclean all
