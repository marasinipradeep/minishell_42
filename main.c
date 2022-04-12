/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:21:48 by bsemmler          #+#    #+#             */
/*   Updated: 2022/04/11 16:21:49 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int		i;
	char	*input;
	char	**s_input;

	//Loops infinitely, exiting can be handled later -b
	i = 0;
	while (i == 0)
	{
		input = readline("minishell& ");
		add_history(input);
		//check that user has input a valid command -b
		if (check_valid_command(input) == 1)
		{
			//do stuff with input here -b
			s_input = split_input(input);
			printf("Command: %s\nContent: %s\n", s_input[0], s_input[1]);
			//Free split input. Will probably move this to a function later -b
			free(s_input[0]);
			if (s_input[1] != NULL)
				free(s_input[1]);
			free(s_input);
		}
		else
		{
			//Error message when command is invalid. 
			//We should print the command the user entered as well -b 
			printf("minishell: command not found\n");
		}
		free(input);
	}
}
