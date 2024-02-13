/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:37:33 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/13 14:53:40 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*read_instructions(void)
{
	int		bread;
	char	*buffer;
	char	*instructions;

	bread = 1;
	buffer = (char *)malloc(1);
	instructions = (char *)malloc(1);
	instructions[0] = 0;
	while (bread == 1)
	{
		buffer[0] = 0;
		bread = read(0, buffer, 1);
		instructions = join_buffer(buffer, instructions);
	}
	free(buffer);
	return (instructions);
}

void	exec_action(t_ab *ab, char *instruct)
{
	if (!ft_strcmp(instruct, "pa"))
		spa(ab);
	else if (!ft_strcmp(instruct, "pb"))
		spb(ab);
	else if (!ft_strcmp(instruct, "sa"))
		ssa(ab);
	else if (!ft_strcmp(instruct, "sb"))
		ssb(ab);
	else if (!ft_strcmp(instruct, "ra"))
		sra(ab);
	else if (!ft_strcmp(instruct, "rb"))
		srb(ab);
	else if (!ft_strcmp(instruct, "rra"))
		srra(ab);
	else if (!ft_strcmp(instruct, "rrb"))
		srrb(ab);
	else if (!ft_strcmp(instruct, "ss"))
		sss(ab);
	else if (!ft_strcmp(instruct, "rr"))
		srr(ab);
	else if (!ft_strcmp(instruct, "rrr"))
		srrr(ab);
}

int	verify_instructions(char **instructions, t_pile *pile)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		if (!is_an_instruct(instructions[i]))
		{
			destroy_pile(pile);
			destroy_arg(instructions);
			ft_perror("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	checker(char **instructions, t_ab *ab)
{
	int	i;

	i = 0;
	while (instructions[i])
		exec_action(ab, instructions[i++]);
	if (is_sorted(ab->pile_a) && !ab->pile_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	i = 0;
	while (instructions[i])
	{
		free(instructions[i]);
		i++;
	}
	free(instructions);
	destroy_piles(ab);
}

int	main(int argc, char *argv[])
{
	t_ab	ab;
	char	*raw_instructions;
	char	**instructions;
	int		i;

	ab.pile_b = NULL;
	i = 0;
	if (argc < 2)
		exit(0);
	else
		ab.pile_a = create_first_pile(argv + 1);
	if (!ab.pile_a)
	{
		ft_perror("Error\n");
		return (0);
	}
	raw_instructions = read_instructions();
	instructions = parse_instructions(raw_instructions);
	if (!verify_instructions(instructions, ab.pile_a))
		return (0);
	checker(instructions, &ab);
	return (0);
}
