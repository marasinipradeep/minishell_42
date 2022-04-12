NAME = minishell

c_flags = -Wall -Werror -Wextra -lreadline

FILES = main.c

all:
	$(MAKE) -C libft
	gcc $(c_flags) -o $(NAME) libft/libft.a $(FILES)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all