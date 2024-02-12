/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_combine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:44:16 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 11:44:48 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	combine_rotates(t_ab *ab, t_pile *cheapest, t_pile *target)
{
	int	i;
	int	max;
	int	diff;

	if (cheapest->cost == 0 || target->cost == 0)
		return ;
	diff = target->cost - cheapest->cost;
	if (diff < 0)
		diff = -diff;
	if (target->cost > cheapest->cost)
		max = target->cost;
	else
		max = cheapest->cost;
	i = max - diff;
	rrn(ab, i);
	target->cost -= i;
	cheapest->cost -= i;
}

void	combine_r_rotates(t_ab *ab, t_pile *cheapest, t_pile *target)
{
	int	i;
	int	max;
	int	diff;

	if (cheapest->cost == 0 || target->cost == 0)
		return ;
	diff = target->cost - cheapest->cost;
	if (diff < 0)
		diff = -diff;
	if (target->cost > cheapest->cost)
		max = target->cost;
	else
		max = cheapest->cost;
	i = max - diff;
	rrrn(ab, i);
	target->cost -= i;
	cheapest->cost -= i;
}
