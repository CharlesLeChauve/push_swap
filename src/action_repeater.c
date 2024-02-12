/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_repeater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:41:19 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 08:43:33 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rran(t_ab *ab, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		rra(ab);
}

void	ran(t_ab *ab, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		ra(ab);
}

void	rrbn(t_ab *ab, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		rrb(ab);
}

void	rbn(t_ab *ab, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		rb(ab);
}
