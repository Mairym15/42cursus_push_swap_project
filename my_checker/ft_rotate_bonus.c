/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:08:02 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/10/12 22:11:38 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	rotate_a_bonus(t_pile **a)
{
	t_pile	*tmp;

	tmp = *a;
	if (*a != NULL && (*a)->next != NULL)
	{
		while ((*a)->next != NULL)
			*a = (*a)->next;
		(*a)->next = tmp;
		*a = tmp->next;
		tmp->next = NULL;
	}
}

void	rotate_b_bonus(t_pile **b)
{
	t_pile	*tmp;

	tmp = *b;
	if (*b != NULL && (*b)->next != NULL)
	{
		while ((*b)->next != NULL)
			*b = (*b)->next;
		(*b)->next = tmp;
		*b = tmp->next;
		tmp->next = NULL;
	}
}

void	rotate_a_and_b_bonus(t_pile **a, t_pile **b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;

	tmp_a = *a;
	if (*a != NULL && *b != NULL && (*a)->next != NULL
		&& (*b)->next != NULL)
	{
		while ((*a)->next != NULL)
			*a = (*a)->next;
		(*a)->next = tmp_a;
		*a = tmp_a->next;
		tmp_a->next = NULL;
		tmp_b = *b;
		while ((*b)->next != NULL)
			*b = (*b)->next;
		(*b)->next = tmp_b;
		*b = tmp_b->next;
		tmp_b->next = NULL;
	}
}
