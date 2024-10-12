/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:27:09 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/01 10:38:31 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_back_in_place_list_medium(t_lst *lst, int bool)
{
	if (bool == 1)
	{
		while (lst->a->index != 0)
			rotate_a(lst);
	}
	else
	{
		while (lst->a->index != 0)
			reverse_rotate_a(lst, 0);
	}
}

static void	fill_b_medium(t_lst *lst, t_var v)
{
	while (lst->a->next->next != NULL && lst->a->index != v.max_a)
	{
		push_b(lst);
		if (lst->a->next->next != NULL && lst->a->index == v.max_a)
		{
			rotate_a(lst);
			if (lst->a->index == v.max_a)
				rotate_a(lst);
		}
	}
}

void	sort_medium_lists(t_lst *lst)
{
	t_var	v;
	int		move;

	v.max_a = get_max(&(lst->a));
	move = 0;
	if (lst->a->index == v.max_a)
		rotate_a(lst);
	fill_b_medium(lst, v);
	if (check_if_sorted(lst->a) == 1)
		sort_with_three(lst);
	sort_list(lst, v, move);
	if (check_position(lst->a, 0) == 1)
		put_back_in_place_list_medium(lst, 1);
	else
		put_back_in_place_list_medium(lst, 0);
}
