/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:41:30 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/13 14:27:04 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

# define IMX 2147483647
# define IMN -2147483648

typedef struct s_pile
{
	int				nb;
	int				index;
	int				cost;
	int				dir;
	struct s_pile	*target;
	struct s_pile	*next;
	struct s_pile	*prev;
}			t_pile;

typedef struct s_ab
{
	t_pile	*pile_a;
	t_pile	*pile_b;
}			t_ab;

void	sa(t_ab *ab);
void	ra(t_ab *ab);
void	rra(t_ab *ab);
void	pa(t_ab *ab);
void	sb(t_ab *ab);
void	rb(t_ab *ab);
void	rrb(t_ab *ab);
void	pb(t_ab *ab);
void	ss(t_ab *ab);
void	rr(t_ab *ab);
void	rrr(t_ab *ab);

void	rrbn(t_ab *ab, int n);
void	rran(t_ab *ab, int n);
void	ran(t_ab *ab, int n);
void	rbn(t_ab *ab, int n);
void	rrn(t_ab *ab, int n);
void	rrrn(t_ab *ab, int n);

void	swap(t_pile **pile);
void	rotate(t_pile **pile);
void	reverse_rotate(t_pile **pile);
void	push(t_pile **src, t_pile **dst);

t_pile	*new_pile_node(int value);
t_pile	*pile_last(t_pile *pile);
t_pile	*get_lower(t_pile *pile);
t_pile	*get_upper(t_pile *pile);
void	pile_add_back(t_pile **pile, t_pile *new);
void	pile_add_front(t_pile **pile, t_pile *new);
int		pile_size(t_pile *pile);

t_pile	*create_first_pile(char **av);

void	ft_perror(char *str);
void	print_piles(t_ab ab);

void	set_indexes(t_ab *ab);
void	set_costs(t_ab *ab);
void	set_targets(t_ab *ab);
int		is_sorted(t_pile *pile);

int		get_dir(t_pile *pile, t_pile *node);
t_pile	*get_min_node(t_pile *pile);
t_pile	*get_cheapest(t_ab *ab);

int		total_cost(t_pile *node, t_ab *ab);

void	put_targets_on_top(t_ab *ab, t_pile *cheapest, t_pile *target);
void	put_min_on_top(t_ab *ab);

void	combine_rotates(t_ab *ab, t_pile *cheapest, t_pile *target);
void	combine_r_rotates(t_ab *ab, t_pile *cheapest, t_pile *target);

void	destroy_piles(t_ab *ab);
void	destroy_arg(char **arg);
long	ft_atol(const char *str);
void	destroy_pile(t_pile *pile);
void	destroy_arg(char **arg);

#endif //PUSH_SWAPH_H
