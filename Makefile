NAME = libftprintf.a

SOURCES = src/ft_printf.c src/ft_printf_utils.c src/ft_printf_utils2.c src/ft_printf_utils3.c \

all: $(NAME)

$(NAME):
	cc -c -Wall -Wextra -Wall $(SOURCES)
	ar rcs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re