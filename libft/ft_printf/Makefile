NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include
RM = rm -f

SRCS = src/ft_printf.c src/ft_printid.c src/ft_printstr.c \
	src/ft_printu.c src/ft_printp.c src/ft_printhex.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
