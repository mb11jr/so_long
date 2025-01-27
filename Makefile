NAME = so_long
BONUS = bonus
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
HEADERS = $(addprefix includes/, so_long.h structures.h)
INCLUDES =  -Iincludes -I/usr/local/include
MLX_FLAGS = -L/usr/local/lib -lmlx_Linux -lXext -lX11 -lm -lz
_SRC = so_long.c game_utils.c draw.c \
	free.c read_map.c map_parser.c map_parser_utils.c \
	image_utils.c check_utils.c utils.c
_BONUS_SRC = so_long_bonus.c game_utils_bonus.c draw_bonus.c \
			free_bonus.c read_map_bonus.c map_parser_bonus.c map_parser_utils_bonus.c \
			image_utils_bonus.c check_utils_bonus.c utils_bonus.c
SRC = $(addprefix sources/, $(_SRC))
OBJ = $(SRC:.c=.o)
BONUS_SRC = $(addprefix bonus_sources/, $(_BONUS_SRC))
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

bonus : $(BONUS)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "█▀ █▀█ █░░ █▀█ █▄░█ █▀▀"
	@echo "▄█ █▄█ █▄▄ █▄█ █░▀█ █▄█"
	@echo "Compiling source files...⏳"
	@echo "Done ✅"
	@echo "Compiling ft_printf, libft, and GNL source files...⏳"
	@make -C ft_printf
	@make -C get_next_line
	@echo "Done ✅"
	@echo "Linking...⏳"
	@$(CC) $(CFLAGS) $(OBJ) ./get_next_line/gnl.a ./ft_printf/libftprintf.a $(MLX_FLAGS) -o $(NAME)
	@echo "Your $(NAME) game 🕹️  is ready"

$(BONUS) : $(BONUS_OBJ)
	@echo "█▀ █▀█ █░░ █▀█ █▄░█ █▀▀"
	@echo "▄█ █▄█ █▄▄ █▄█ █░▀█ █▄█"
	@echo "Compiling source files...⏳"
	@echo "Done ✅"
	@echo "Compiling ft_printf, libft, and GNL source files...⏳"
	@make -C ft_printf
	@make -C get_next_line
	@echo "Done ✅"
	@echo "Linking...⏳"
	$(CC) $(CFLAGS) $(BONUS_OBJ) ./get_next_line/gnl.a ./ft_printf/libftprintf.a $(MLX_FLAGS) -o $(BONUS)
	@echo "Your $(NAME) game 🕹️  is ready"

clean:
	@echo "Cleaning object files...🚮"
	@make -C ft_printf clean
	@make -C get_next_line clean
	@$(RM) $(OBJ)
	@$(RM) $(BONUS_OBJ)
	@echo "Done ✅"

fclean : clean
	@echo "Full clean begins... 🚮"
	@$(RM) $(NAME) $(BONUS)
	@make -C ft_printf fclean
	@make -C get_next_line fclean
	@echo "Full clean is done ✅"

re : fclean all

.PHONY: all clean fclean re
