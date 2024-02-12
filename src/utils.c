/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:40:18 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 16:36:43 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_pile *pile)
{
	int	prev_nb;

	prev_nb = pile->nb;
	pile = pile->next;
	while (pile)
	{
		if (pile->nb < prev_nb)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((int)((unsigned char) s1[i] - (unsigned char) s2[i]));
		i++;
	}
	return (0);
}

int	greater(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int	total_cost(t_pile *node, t_ab *ab)
{
	int	a_dir;
	int	b_dir;

	a_dir = get_dir(ab->pile_a, node->target);
	b_dir = get_dir(ab->pile_b, node);
	if (a_dir == b_dir)
		return (greater(node->cost, node->target->cost));
	return (node->cost + node->target->cost);
}

void	destroy_pile(t_ab *ab)
{
	t_pile	*node;
	t_pile	*next;

	node = ab->pile_a;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
}
