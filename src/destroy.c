/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:25:37 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/13 14:53:22 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	destroy_pile(t_pile *pile)
{
	t_pile	*node;
	t_pile	*next;

	node = pile;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

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
