/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:25:21 by bsemmler          #+#    #+#             */
/*   Updated: 2022/04/12 16:25:21 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_command(char *input, char *to_check);

int	check_valid_command(char *input)
{
	//Check inputted command against list of commands -b
	if (check_command(input, "echo") == 1
		|| check_command(input, "cd") == 1
		|| check_command(input, "pwd") == 1
		|| check_command(input, "export") == 1
		|| check_command(input, "unset") == 1
		|| check_command(input, "env") == 1
		|| check_command(input, "exit") == 1
		|| ft_strncmp(input, "./", 2) == 0)
		return (1);
	return (0);
}

int	check_command(char *input, char *to_check)
{
	//check if command is inputted without options -b
	if (ft_strlen(input) == ft_strlen(to_check))
	{
		if (ft_strncmp(input, to_check, ft_strlen(to_check)) == 0)
			return (1);
	}
	//check if command is inputted with options -b
	else if (ft_strncmp(input, ft_strjoin(to_check, " "),
			ft_strlen(to_check) + 1) == 0)
		return (1);
	return (0);
}
