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

char	*switch_command(char *input)
{
	int		c_id;
	char	**s_input;
	char	*output;

	//Splits the input into the command and the options.
	c_id = get_command_id(input);
	s_input = split_input(input);
	output = NULL;
	if (c_id == -1)
		//Invalid command
		output = ft_joinfree(ft_strjoin("minishell: ", s_input[0]), 1,
			": command not found\n", 0);
	else if (c_id == 0)
		//command './'
		output = ft_joinfree(ft_strjoin("COMMAND '", s_input[0]), 1,
			"' NOT YET IMPLEMENTED\n", 0);
	else if (c_id == 1)
		//command 'echo'
		output = ft_joinfree(ft_strjoin("COMMAND '", s_input[0]), 1,
			"' NOT YET IMPLEMENTED\n", 0);
	else if (c_id == 2)
		//command 'cd'
		output = command_cd(s_input);
	else if (c_id == 3)
		//command 'pwd'
		output = command_pwd(s_input);
	else if (c_id == 4)
		//command 'export'
		output = ft_joinfree(ft_strjoin("COMMAND '", s_input[0]), 1,
			"' NOT YET IMPLEMENTED\n", 0);
	else if (c_id == 5)
		//command 'unset'
		output = ft_joinfree(ft_strjoin("COMMAND '", s_input[0]), 1,
			"' NOT YET IMPLEMENTED\n", 0);
	else if (c_id == 6)
		//command 'env'
		output = ft_joinfree(ft_strjoin("COMMAND '", s_input[0]), 1,
			"' NOT YET IMPLEMENTED\n", 0);
	else if (c_id == 7)
		//command 'exit'
		output = ft_joinfree(ft_strjoin("COMMAND '", s_input[0]), 1,
			"' NOT YET IMPLEMENTED\n", 0);
	free_split_input(s_input);
	return (output);
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
