/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:21:03 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/28 15:26:24 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "Libft/libft.h"
# include "push_swap.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		main(int ac, char **av);

t_pile	*parse_check_bonus(int ac, char **av);

void	push_a_bonus(t_pile **a, t_pile **b);
void	push_b_bonus(t_pile **a, t_pile **b);
void	swap_a_bonus(t_pile **a);
void	swap_b_bonus(t_pile **b);
void	swap_a_and_b_bonus(t_pile **a, t_pile **b);
void	rotate_a_bonus(t_pile **a);
void	rotate_b_bonus(t_pile **b);
void	rotate_a_and_b_bonus(t_pile **a, t_pile **b);
void	reverse_rotate_a_bonus(t_pile **a);
void	reverse_rotate_b_bonus(t_pile **b);
void	reverse_rotate_a_and_b_bonus(t_pile **a, t_pile **b);

#endif