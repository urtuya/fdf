NAME = fdf

SRC_DIR = src/
CFILES = main.c init.c draw.c iso.c key_hooks.c rotation.c\
		perspective.c put_pixel.c helping.c error.c mouse_hooks.c\
		color.c #wu.c
SRC = $(addprefix $(SRC_DIR), $(CFILES))
FLAG = -Wall -Wextra -Werror
UNAME := $(shell uname -s)
LIBFT_DIR = libft/
LIB = $(LIBFT_DIR)libft.a
INC = -I include/ -I $(LIBFT_DIR)inc/
INCS = include/head.h
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(CFILES:.c=.o))

ifeq ($(UNAME), Darwin)
	TOOL = -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
	TOOL = -L/usr/X11/lib /usr/X11/lib/libmlx_Linux.a -lXext -lX11 -lm
endif

all: $(NAME)
	
$(NAME): $(OBJ_DIR) $(OBJ) $(INCS) $(LIB)
	gcc  $(FLAG) $(OBJ) -L $(LIBFT_DIR) -lft $(TOOL) -o $(NAME)

$(LIB):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	@gcc -c -g $(FLAG) $(INC) $< -o $@

clean:
	make clean -C libft
	rm -r $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all, clean, fclean, re