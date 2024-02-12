/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_action_repeater.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:43:19 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 08:48:35 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrn(t_ab *ab, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		rr(ab);
}

void	rrrn(t_ab *ab, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		rrr(ab);
}
