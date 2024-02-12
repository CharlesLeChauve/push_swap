/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:53:26 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 15:52:07 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_indexes(t_ab *ab)
{
	t_pile	*act;
	int		index;

	act = ab->pile_a;
	index = 0;
	while (act)
	{
		act->index = index;
		act = act->next;
		index++;
	}
	index = 0;
	act = ab->pile_b;
	while (act)
	{
		act->index = index;
		act = act->next;
		index++;
	}
}

void	set_costs(t_ab *ab)
{
	int		size;
	t_pile	*act;

	size = pile_size(ab->pile_a);
	act = ab->pile_a;
	while (act)
	{
		if (act->index <= size / 2)
			act->cost = act->index;
		else
			act->cost = size - act->index;
		act = act->next;
	}
	size = pile_size(ab->pile_b);
	act = ab->pile_b;
	while (act)
	{
		if (act->index <= size / 2)
			act->cost = act->index;
		else
			act->cost = size - act->index;
		act = act->next;
	}
}

void	set_node_target(t_pile *node, t_pile *pile_a)
{
	int		lwst_grtr_vlue;
	t_pile	*act;
	t_pile	*target;

	lwst_grtr_vlue = IMX;
	act = pile_a;
	while (act)
	{
		if (act->nb > node->nb && act->nb < lwst_grtr_vlue)
		{
			lwst_grtr_vlue = act->nb;
			target = act;
		}
		act = act->next;
	}
	if (lwst_grtr_vlue == IMX)
	{
		target = get_min_node(pile_a);
	}
	node->target = target;
}

void	set_targets(t_ab *ab)
{
	t_pile	*node;

	node = ab->pile_b;
	while (node)
	{
		set_node_target(node, ab->pile_a);
		node = node->next;
	}
}
