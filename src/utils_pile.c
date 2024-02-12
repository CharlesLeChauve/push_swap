/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:26:39 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 15:06:57 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_pile	*new_pile_node(int value)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof (t_pile));
	if (!new)
		return (NULL);
	new->nb = value;
	new->next = NULL;
	new->prev = NULL;
	new->target = NULL;
	return (new);
}

t_pile	*pile_last(t_pile *pile)
{
	t_pile	*last;

	last = pile;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

void	pile_add_back(t_pile **pile, t_pile *new)
{
	t_pile	*last_node;

	if (!*pile)
	{
		new->next = NULL;
		new->prev = NULL;
		*pile = new;
	}
	else
	{
		last_node = pile_last(*pile);
		new->prev = last_node;
		last_node->next = new;
		new->next = NULL;
	}
}

void	pile_add_front(t_pile **pile, t_pile *new)
{
	if (*pile == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*pile = new;
	}
	else
	{
		new->prev = NULL;
		(*pile)->prev = new;
		new->next = *pile;
		*pile = new;
	}
}

int	pile_size(t_pile *pile)
{
	int		i;
	t_pile	*node;

	if (pile == NULL)
		return (0);
	i = 0;
	node = pile;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
