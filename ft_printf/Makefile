NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include
RM = rm -f
SRCS = $(addprefix src/, ft_printf.c ft_printid.c ft_printstr.c ft_printu.c ft_printp.c ft_printhex.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@make -C ../libft
	@cp ../libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

clean :
	@$(MAKE) clean -C ../libft
	@$(RM) $(OBJS)

fclean : clean
	@$(MAKE) fclean -C ../libft
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
