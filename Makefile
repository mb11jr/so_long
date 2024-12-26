NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -Imlx_linux
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib/X11 -lXext -lX11 -lm -lz
SRC = main.c
OBJ = $(SRC:.c=.o) 


all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re