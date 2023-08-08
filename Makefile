NAME = cub3D

LBFT = libft/libft.a

GNL = gnl/gnl.a

SRC = main.c get_cub.c check_map.c check_utils.c parse_color.c parse_texture.c assign_parsed.c

CC = gcc -g

RM = rm -f

FLAGS = #-Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit -g

MLXS = #./mlx/libmlx.a

all: $(NAME)
$(MLXS):
	make -C ./mlx
$(LBFT):
	make -C ./libft
$(GNL):
	make -C ./gnl
$(NAME): $(MLXS) $(GNL) $(LBFT) $(SRC)
	$(CC) $(FLAGS) $(SRC) $(GNL) $(LBFT) $(MLXS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(NAME)
	make clean -C ./mlx
	make fclean -C ./libft
	make fclean -C ./gnl

fclean: clean

re: fclean all

.PHONY: all clean fclean re
