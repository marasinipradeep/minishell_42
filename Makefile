NAME = minishell

c_flags = -Wall -Werror -Wextra -lreadline

FILES = main.c\
		check_valid_command.c\
		split_input.c

all:
	$(MAKE) -C libft
	gcc $(c_flags) -o $(NAME) libft/libft.a $(FILES)

clean:

fclean:
	rm -rf $(NAME)

norm:
	norminette $(FILES)

re: fclean all