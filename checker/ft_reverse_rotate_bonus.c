/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:04:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/27 16:15:52 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_bonus(t_pile *a)
{
	t_pile	*current;
	t_pile	*tmp;
	t_pile	*last;
	t_move	*next;

	tmp = a;
	last = a;
	current = a->next;
	while (last->next->next != NULL)
		last = last->next;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	a = current;
	last->next = NULL;
}

void	reverse_rotate_b_bonus(t_pile *b)
{
	t_pile	*current;
	t_pile	*tmp;
	t_pile	*last;
	t_move	*next;

	tmp = b;
	last = b;
	current = b->next;
	while (last->next->next != NULL)
		last = last->next;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	b = current;
	last->next = NULL;
}

void	reverse_rotate_a_and_b_bonus(t_pile *a, t_pile *b)
{
	t_move	*next;

	reverse_rotate_a_bonus(a);
	reverse_rotate_b_bonus(b);
}
