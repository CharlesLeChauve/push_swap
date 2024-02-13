/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:41:54 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/13 14:19:49 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	ssa(t_ab *ab);
void	spa(t_ab *ab);
void	sra(t_ab *ab);
void	srra(t_ab *ab);
void	ssb(t_ab *ab);
void	spb(t_ab *ab);
void	srb(t_ab *ab);
void	srrb(t_ab *ab);
void	sss(t_ab *ab);
void	srr(t_ab *ab);
void	srrr(t_ab *ab);

int		ft_strcmp(const char *s1, const char *s2);

void	destroy_pile(t_pile *pile);
char	**parse_instructions(char *raw);
int		is_an_instruct(char *instruct);
char	*join_buffer(char *buffer, char *line);

#endif //CHECKER_H
