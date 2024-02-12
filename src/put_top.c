/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:42:14 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 12:05:17 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_on_top_a(t_ab *ab, t_pile *target)
{
	int		dir;
	t_pile	**pile;

	pile = &(ab->pile_a);
	if (target->index <= pile_size(*pile) / 2)
		dir = 1;
	else
		dir = -1;
	if (dir == 1)
		ran(ab, target->cost);
	else
		rran(ab, target->cost);
}

void	put_on_top_b(t_ab *ab, t_pile *target)
{
	int		dir;
	t_pile	**pile;

	pile = &(ab->pile_b);
	if (target->index <= pile_size(*pile) / 2)
		dir = 1;
	else
		dir = -1;
	if (dir == 1)
		rbn(ab, target->cost);
	else
		rrbn(ab, target->cost);
}

void	put_targets_on_top(t_ab *ab, t_pile *cheapest, t_pile *target)
{
	int	a_dir;
	int	b_dir;

	a_dir = get_dir(ab->pile_a, target);
	b_dir = get_dir(ab->pile_b, cheapest);
	if (a_dir == b_dir && a_dir == 1)
		combine_rotates(ab, cheapest, target);
	else if (a_dir == b_dir && a_dir == -1)
		combine_r_rotates(ab, cheapest, target);
	put_on_top_a(ab, target);
	put_on_top_b(ab, cheapest);
}

void	put_min_on_top(t_ab *ab)
{
	t_pile	*min;

	min = get_lower(ab->pile_a);
	set_indexes(ab);
	if (min->index <= pile_size(ab->pile_a) / 2)
		ran(ab, min->index);
	else
		rran(ab, pile_size(ab->pile_a) - min->index);
}
