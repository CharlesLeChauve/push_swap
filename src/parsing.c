/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:22:38 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 16:51:44 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	destroy_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

int	already_seen(int value, t_pile *pile)
{
	t_pile	*actual;

	actual = pile;
	while (actual != NULL)
	{
		if (actual->nb == value)
			return (1);
		actual = actual->next;
	}
	return (0);
}

int	check_arg(char *arg, long value, t_pile *pile)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((!ft_isdigit(arg[i]) && i != 0) || ((i == 0 && arg[i] != '-')
				&& (i == 0 && arg[i] != '+') && !ft_isdigit(arg[i])))
			return (0);
		if (already_seen((int)value, pile))
			return (0);
		i++;
	}
	return (1);
}

t_pile	*create_first_pile(char **av)
{
	t_pile	*pile;
	t_pile	*new;
	char	**actual_arg;
	long	value;
	int		i;
	int		j;

	pile = NULL;
	i = -1;
	while (av[++i])
	{
		actual_arg = ft_split(av[i], ' ');
		j = -1;
		while (actual_arg[++j])
		{
			value = ft_atol(actual_arg[j]);
			if (!(value <= IMX) || !(value >= IMN)
				|| !check_arg(actual_arg[j], value, pile))
			{
				destroy_arg(actual_arg);
				return (NULL);
			}
			new = new_pile_node(value);
			pile_add_back(&pile, new);
		}
		destroy_arg(actual_arg);
	}
	return (pile);
}
