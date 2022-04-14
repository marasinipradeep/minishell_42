NAME = minishell

c_flags = -Wall -Werror -Wextra -lreadline

FILES = main.c\
		switch_command.c\
		get_command_id.c\
		command_cd.c\
		command_pwd.c

all:
	$(MAKE) -C libft
	gcc $(c_flags) -o $(NAME) libft/libft.a $(FILES)

clean:

fclean:
	rm -rf $(NAME)

norm:
	norminette $(FILES)

re: fclean all