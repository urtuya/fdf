SRC = main.c read_map.c draw_line.c projection.c rotation.c
TOOL = -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all:
	gcc -g $(SRC) $(TOOL) libft/libft.a

clean:
	make clean -C libft
	rm *.o
