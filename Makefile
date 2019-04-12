NAME = minishell
SRC = shell/*.c shell/helpers/*.c shell/lexer/*.c shell/reader/*.c shell/autocomplete/*.c shell/executer/*.c shell/signals/*.c
OBJ = $(SRC:.c = .o)
LIBFT = -L libft -lft
TERMCAP = -ltermcap
INC = -I shell/includes -I libft/includes
FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	make re -C libft
	gcc $(FLAGS) $(OBJ) $(INC) $(LIBFT) $(TERMCAP) -o $(NAME)
	make clean -C libft

all: $(NAME)

fclean:
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
