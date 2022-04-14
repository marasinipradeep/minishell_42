/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:23:22 by bsemmler          #+#    #+#             */
/*   Updated: 2022/04/14 17:23:24 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_input(char *input);
void	free_split_input(char **s_input);

void	switch_command(char *input)
{
	int		c_id;
	char	**s_input;

	//Splits the input into the command and the options. This approach
	//will also not work for pipes, so we will need to modify it later
	c_id = get_command_id(input);
	s_input = split_input(input);
	if (c_id == -1)
		//Invalid command
		printf("minishell: %s: command not found\n", s_input[0]);
	else if (c_id == 0)
		//command './'
		printf("COMMAND '%s' NOT YET IMPLEMENTED\n", s_input[0]);
	else if (c_id == 1)
		//command 'echo'
		printf("COMMAND '%s' NOT YET IMPLEMENTED\n", s_input[0]);
	else if (c_id == 2)
		//command 'cd'
		printf("COMMAND '%s' NOT YET IMPLEMENTED\n", s_input[0]);
	else if (c_id == 3)
		//command 'pwd'
		printf("COMMAND '%s' NOT YET IMPLEMENTED\n", s_input[0]);
	else if (c_id == 4)
		//command 'export'
		printf("COMMAND '%s' NOT YET IMPLEMENTED\n", s_input[0]);
	else if (c_id == 5)
		//command 'unset'
		printf("COMMAND '%s' NOT YET IMPLEMENTED\n", s_input[0]);
	else if (c_id == 6)
		//command 'env'
		printf("COMMAND '%s' NOT YET IMPLEMENTED\n", s_input[0]);
	else if (c_id == 7)
		//command 'exit'
		printf("COMMAND '%s' NOT YET IMPLEMENTED\n", s_input[0]);
	free_split_input(s_input);
}

char	**split_input(char *input)
{
	char	**s_input;
	int		i;

	//Split input into the command and options -b
	s_input = malloc(sizeof(char *) * 2);
	i = 0;
	while (input[i] != ' ' && input[i])
		i++;
	s_input[0] = malloc(sizeof(char) * (i + 1));
	if (input[i] != 0 && input[i + 1] != 0)
	{
		s_input[1] = malloc(sizeof(char) * (ft_strlen(input) - i - 1));
		s_input[1] = ft_strdup(&input[i + 1]);
	}
	else
		s_input[1] = NULL;
	input[i] = 0;
	i--;
	while (i >= 0)
	{
		s_input[0][i] = input[i];
		i--;
	}
	return (s_input);
}

void	free_split_input(char **s_input)
{
	//Free the split input
	free(s_input[0]);
	if (s_input[1] != NULL)
		free(s_input[1]);
	free(s_input);
}
