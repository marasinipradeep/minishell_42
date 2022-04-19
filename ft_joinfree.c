/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:09:21 by bsemmler          #+#    #+#             */
/*   Updated: 2022/04/19 17:09:22 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Same as ft_strjoin but has the option to free strings used as input

char	*ft_joinfree(char *str1, int free1, char *str2, int free2)
{
	char	*joined;
	int		pos;
	int		i;

	joined = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	pos = 0;
	i = 0;
	while (str1[i])
	{
		joined[pos] = str1[i];
		pos++;
		i++;
	}
	i = 0;
	while (str2[i])
	{
		joined[pos] = str2[i];
		pos++;
		i++;
	}
	joined[pos] = 0;
	if (free1 == 1)
		free(str1);
	if (free2 == 1)
		free(str2);
	return (joined);
}
