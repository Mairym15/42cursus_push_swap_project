/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:28:46 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/28 16:23:44 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_pile *a)
{
	t_pile	*tmp;

	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->index < (tmp->next)->index)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

void	sort_with_three(t_lst *lst)
{
	t_pile	*middle;
	t_pile	*last;

	while (check_if_sorted(lst->a) == 1)
	{
		last = ft_lst_last(lst->a);
		middle = (lst->a->next);
		if (check_if_sorted(lst->a) == 1 && (middle->index > last->index
				|| last->index < lst->a->index) && last->index > lst->a->index)
			reverse_rotate_a(lst, 0);
		else if (check_if_sorted(lst->a) == 1 && lst->a->index > last->index)
			rotate_a(lst);
		else if (check_if_sorted(lst->a) == 1 && lst->a->index > middle->index)
			swap_a(lst);
	}
}

static void	add_number_and_sort(t_lst *lst)
{
	t_pile	*last;
	t_pile	*middle;

	while (check_if_sorted(lst->a) == 1)
	{
		last = ft_lst_last(lst->a);
		middle = (lst->a->next);
		if (check_if_sorted(lst->a) == 1 && lst->a->index > last->index)
			rotate_a(lst);
		else if (check_if_sorted(lst->a) == 1
			&& lst->a->index > lst->a->next->index)
			swap_a(lst);
		else if (check_if_sorted(lst->a) == 1 && middle->index > last->index)
			reverse_rotate_a(lst, 0);
		else
		{
			while (lst->a->index < lst->a->next->index)
				push_b(lst);
			if (check_if_sorted(lst->a) == 1
				&& lst->a->index > lst->a->next->index)
				swap_a(lst);
			while (ft_lst_size(lst->b) > 0)
				push_a(lst);
		}
	}
}

void	sort_with_five(t_lst *lst)
{	
	while (ft_lst_size(lst->a) > 3)
	{
		while (check_if_sorted(lst->a) == 1 && lst->a->index >= 3)
			rotate_a(lst);
		while (check_if_sorted(lst->a) == 1
			&& (ft_lst_last(lst->a)->index < lst->a->index))
			reverse_rotate_a(lst, 0);
		push_b(lst);
	}
	sort_with_three(lst);
	while (ft_lst_size(lst->b) > 0)
	{
		if (lst->b->next != NULL && lst->b->index < lst->b->next->index)
			swap_b(lst);
		push_a(lst);
		add_number_and_sort(lst);
	}
}

void	push_swap(t_pile *nb_to_sort, int size)
{
	t_lst	lst;

	lst.a = nb_to_sort;
	lst.b = NULL;
	lst.move_list = NULL;
	if (lst.a->next == NULL)
		return ;
	if (check_if_sorted(lst.a) == 1)
	{
		if (size == 2)
			swap_a(&lst);
		else if (size == 3)
			sort_with_three(&lst);
		else if (size >= 4 && size <= 6)
			sort_with_five(&lst);
		else
			sort_big_lists(&lst);
	}
	print_list_move(lst.move_list);
	free_list(lst.b);
	free_list(lst.a);
}
