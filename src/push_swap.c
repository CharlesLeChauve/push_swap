/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:09:49 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 16:41:08 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_ab *ab)
{
	t_pile	*pile;

	pile = ab->pile_a;
	if (pile->nb > pile->next->nb && pile->next->nb > pile->next->next->nb)
	{
		sa(ab);
		rra(ab);
	}
	else if (pile->nb > pile->next->nb && pile->next->nb < pile->next->next->nb
		&& pile->next->next->nb > pile->nb)
		sa(ab);
	else if (pile->nb > pile->next->nb && pile->next->nb < pile->next->next->nb
		&& pile->next->next->nb < pile->nb)
		ra(ab);
	else if (pile->nb < pile->next->nb && pile->next->nb > pile->next->next->nb
		&& pile->next->next->nb > pile->nb)
	{
		sa(ab);
		ra(ab);
	}
	else if (pile->nb < pile->next->nb && pile->next->nb > pile->next->next->nb
		&& pile->next->next->nb < pile->nb)
		rra(ab);
}

void	resolve_small(t_ab *ab)
{
	int	ps;

	ps = pile_size(ab->pile_a);
	if (ps <= 1)
		return ;
	else if (ps == 2 && !is_sorted(ab->pile_a))
		sa(ab);
	else if (ps == 3)
		sort_three(ab);
}

void	sort_long(t_ab *ab)
{
	t_pile	*cheapest;

	while (pile_size(ab->pile_a) > 3)
		pb(ab);
	sort_three(ab);
	while (ab->pile_b)
	{
		set_indexes(ab);
		set_targets(ab);
		set_costs(ab);
		cheapest = get_cheapest(ab);
		put_targets_on_top(ab, cheapest, cheapest->target);
		pa(ab);
	}
	put_min_on_top(ab);
}

int	main(int ac, char *av[])
{
	t_ab		ab;

	ab.pile_b = NULL;
	if (ac < 2)
		return (0);
	else
		ab.pile_a = create_first_pile(av + 1);
	if (!ab.pile_a)
	{
		ft_perror("Error\n");
		return (0);
	}
	if (pile_size(ab.pile_a) <= 3)
		resolve_small(&ab);
	else if (!is_sorted(ab.pile_a))
		sort_long(&ab);
	destroy_pile(&ab);
	return (0);
}
