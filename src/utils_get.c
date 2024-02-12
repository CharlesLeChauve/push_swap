/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:44:43 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 08:56:56 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	*get_lower(t_pile *pile)
{
	t_pile	*act;
	t_pile	*lower;

	lower = pile;
	act = pile;
	while (act->next)
	{
		if (act->nb < lower->nb)
			lower = act;
		act = act->next;
	}
	if (act->nb < lower->nb)
		lower = act;
	return (lower);
}

t_pile	*get_upper(t_pile *pile)
{
	t_pile	*act;
	t_pile	*upper;

	upper = pile;
	act = pile;
	while (act->next && act->next != pile)
	{
		if (act->nb > upper->nb)
			upper = act;
		act = act->next;
	}
	if (act->nb > upper->nb)
		upper = act;
	return (upper);
}

int	get_dir(t_pile *pile, t_pile *node)
{
	int	size;

	size = pile_size(pile);
	if (node->index <= size / 2)
		return (1);
	else
		return (-1);
}

t_pile	*get_min_node(t_pile *pile)
{
	t_pile	*act;
	t_pile	*min;

	act = pile;
	min = act;
	while (act)
	{
		if (act->nb < min->nb)
			min = act;
		act = act->next;
	}
	return (min);
}

t_pile	*get_cheapest(t_ab *ab)
{
	t_pile	*cheapest;
	t_pile	*act;
	int		lower_cost;

	act = ab->pile_b;
	cheapest = act;
	lower_cost = total_cost(act, ab);
	while (act)
	{
		if (total_cost(act, ab) < lower_cost)
		{
			cheapest = act;
			lower_cost = total_cost(act, ab);
		}
		act = act->next;
	}
	return (cheapest);
}
