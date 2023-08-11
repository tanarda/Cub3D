NAME = window

SRC = main.c

CC = gcc -g

RM = rm -f

FLAGS = -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit -g

MLXS = ./mlx/libmlx.a

all: $(NAME)
$(MLXS):
	make -C ./mlx
$(NAME): $(MLXS) $(SRC)
	$(CC) $(FLAGS) $(SRC) $(MLXS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(NAME)
	make clean -C ./mlx

fclean: clean

re: fclean all

.PHONY: all clean fclean re
