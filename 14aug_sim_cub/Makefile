NAME = cub3D

LBfT = libft/libft.a

GNL	= gnl/gnl.a

SRC = main.c get_file.c utils.c map.c set_xpm.c set_color.c check.c \
draw.c game.c

CC = gcc

RM = rm -f

fLAGS = -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit

MLXS = ./mlx/libmlx.a

all: $(NAME)

$(MLXS):
	make -C ./mlx

$(LBfT):
	make -C ./libft

$(GNL):
	make -C ./gnl

$(NAME): $(MLXS) $(GNL) $(LBfT) $(SRC)
	$(CC) $(fLAGS) $(SRC) $(GNL) $(LBfT) $(MLXS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C ./mlx
	make fclean -C ./libft
	make fclean -C ./gnl
	rm -rf cub3D

fclean: clean

re: fclean all

.PHONY: all clean fclean re
