/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:41:54 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/12 12:20:36 by tgibert          ###   ########.fr       */
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

#endif //CHECKER_H
