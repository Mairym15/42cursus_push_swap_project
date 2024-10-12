/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:04:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/10/12 22:11:32 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	reverse_rotate_a_bonus(t_pile **a)
{
	t_pile	*current;
	t_pile	*tmp;
	t_pile	*last;

	if ((*a) != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		last = *a;
		current = (*a)->next;
		while (last->next->next != NULL)
			last = last->next;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		*a = current;
		last->next = NULL;
	}
}

void	reverse_rotate_b_bonus(t_pile **b)
{
	t_pile	*current;
	t_pile	*tmp;
	t_pile	*last;

	if ((*b) != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		last = *b;
		current = (*b)->next;
		while (last->next->next != NULL)
			last = last->next;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		*b = current;
		last->next = NULL;
	}
}

void	reverse_rotate_a_and_b_bonus(t_pile **a, t_pile **b)
{
	if (*a != NULL && *b != NULL && (*a)->next != NULL
		&& (*b)->next != NULL)
	{
		reverse_rotate_b_bonus(b);
		reverse_rotate_a_bonus(a);
	}
}
