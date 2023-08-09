NAME = cub3D

LBFT = libft/libft.a

GNL = gnl/gnl.a

SRC = parser/main.c parser/get_cub.c parser/check_map.c parser/check_utils.c \
		parser/assign_parsed.c parser/map_generate.c

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
