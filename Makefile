SRC = src/main.c src/init.c src/draw.c src/iso.c src/hooks.c src/rotation.c src/perspective.c src/put_pixel.c src/init2.c src/error.c
TOOL = -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
NAME = fdf
all: $(NAME)
	
$(NAME):
	gcc -g -I include/ $(SRC) $(TOOL) libft/libft.a -o $(NAME)

clean:
	make clean -C libft
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
