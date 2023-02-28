/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:57:27 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/28 15:33:18 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_bonus(t_pile **a)
{
	t_pile	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
}

void	swap_b_bonus(t_pile **b)
{
	t_pile	*tmp;

	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
}

void	swap_a_and_b_bonus(t_pile **a, t_pile **b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;

	if (*a != NULL && *b != NULL && (*a)->next != NULL
		&& (*b)->next != NULL)
	{
		tmp_a = *a;
		*a = (*a)->next;
		tmp_a->next = (*a)->next;
		(*a)->next = tmp_a;
		tmp_b = *b;
		*b = (*b)->next;
		tmp_b->next = (*b)->next;
		(*b)->next = tmp_b;
	}
}
