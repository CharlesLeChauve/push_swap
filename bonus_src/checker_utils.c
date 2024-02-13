/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:15:49 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/13 14:21:26 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	is_an_instruct(char *instruct)
{
	if (!ft_strcmp(instruct, "ra") && !ft_strcmp(instruct, "rra") && !ft_strcmp(instruct, "rb")
		&& !ft_strcmp(instruct, "rrb") && !ft_strcmp(instruct, "rr") && !ft_strcmp(instruct, "rrr")
		&& !ft_strcmp(instruct, "pa") && !ft_strcmp(instruct, "pb") && !ft_strcmp(instruct, "sa")
		&& !ft_strcmp(instruct, "sb") && !ft_strcmp(instruct, "ss"))
		return (0);
	return (1);
}

char	**parse_instructions(char *raw)
{
	char	**instructions;

	instructions = ft_split(raw, '\n');
	return (instructions);
}

char	*join_buffer(char *buffer, char *line)
{
	int		line_len;
	int		i;
	char	*newl;

	line_len = ft_strlen(line);
	i = -1;
	newl = (char *)malloc(line_len + 2);
	while (++i < line_len)
		newl[i] = line[i];
	newl[i++] = *buffer;
	newl[i] = '\0';
	free(line);
	return (newl);
}
