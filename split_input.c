/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:13:17 by bsemmler          #+#    #+#             */
/*   Updated: 2022/04/12 17:13:23 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
