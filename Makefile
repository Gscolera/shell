NAME = minishell
SRC = shell/*.c shell/helpers/*.c shell/lexer/*.c shell/reader/*.c
OBJ = $(SRC:.c = .o)
LIBFT = -L libft -lft
TERMCAP = -ltermcap
INC = -I shell/includes -I libft/includes
FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	gcc $(OBJ) $(INC) $(LIBFT) $(TERMCAP) -o $(NAME)

all: $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
