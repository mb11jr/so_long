NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES =  -Iincludes -I/usr/local/include
MLX_FLAGS = -L/usr/local/lib -lmlx_Linux -lXext -lX11 -lm -lz
SRC = $(addprefix sources/, so_long.c map_parser.c utils.c)
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	make -C ft_printf
	make -C get_next_line
	$(CC) $(CFLAGS) $(OBJ) ./get_next_line/gnl.a ./ft_printf/libftprintf.a $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	make -C get_next_line fclean
	make -C ft_printf fclean

re : fclean all

.PHONY: all clean fclean re