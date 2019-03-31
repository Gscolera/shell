NAME=libft.a
FLAGS = -c -Wall -Werror -Wextra
FT_PRINTF = ft_printf/ft_printf.c ft_printf/manages/*.c ft_printf/helpers/*.c
SRC = memory/*.c strings/*.c puts/*.c other/*.c $(FT_PRINTF)
INC = includes

$(NAME):
	gcc $(FLAGS) $(SRC) -I $(INC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
