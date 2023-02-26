/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:28:46 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/25 22:49:37 by mkerkeni         ###   ########.fr       */
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

t_lst	*sort_with_three(t_lst *lst)
{
	t_pile	*middle;
	t_pile	*last;

	while (check_if_sorted(lst->a) == 1)
	{
		last = ft_lst_last(lst->a);
		middle = (lst->a->next);
		if (check_if_sorted(lst->a) == 1 && (middle->index > last->index
				|| last->index < lst->a->index))
			lst = reverse_rotate_a(lst);
		else if (check_if_sorted(lst->a) == 1 && lst->a->index > last->index)
			lst = rotate_a(lst);
		else if (check_if_sorted(lst->a) == 1 && lst->a->index > middle->index)
			lst = swap_a(lst);
	}
	return (lst);
}

static t_lst	*add_number_and_sort(t_lst *lst)
{
	t_pile	*last;
	t_pile	*middle;

	while (check_if_sorted(lst->a) == 1)
	{
		last = ft_lst_last(lst->a);
		middle = ((lst->a)->next);
		if (check_if_sorted(lst->a) == 1 && (lst->a)->index > last->index)
			lst = rotate_a(lst);
		else if (check_if_sorted(lst->a) == 1 && lst->a->index > (lst->a->next)->index)
			lst = swap_a(lst);
		else if (check_if_sorted(lst->a) == 1 && middle->index > last->index)
			lst = reverse_rotate_a(lst);
		else
		{
			while ((lst->a)->index < ((lst->a)->next)->index)
				lst = push_b(lst);
			if (check_if_sorted(lst->a) == 1 && (lst->a)->index > (lst->a->next)->index)
				lst = swap_a(lst);
			while (ft_lst_size(lst->b) > 0)
				lst = push_a(lst);
		}
	}
	return (lst);
}

static t_lst	*sort_with_five(t_lst *lst)
{	
	while (ft_lst_size(lst->a) > 3)
	{
		while (check_if_sorted(lst->a) == 1 && lst->a->index >= 3)
		{
			lst = rotate_a(lst);
		}
		while (check_if_sorted(lst->a) == 1
			&& (ft_lst_last(lst->a)->index < (lst->a)->index))
			lst = reverse_rotate_a(lst);
		lst = push_b(lst);
	}
	lst = sort_with_three(lst);
	while (ft_lst_size(lst->b) > 0)
	{
		if ((lst->b)->next != NULL && (lst->b)->index < ((lst->b)->next)->index)
			lst = swap_b(lst);
		lst = push_a(lst);
		lst = add_number_and_sort(lst);
	}
	return (lst);
}

void	push_swap(t_pile *nb_to_sort, int size)
{
	
	t_lst	*lst;
	t_move	*move_list;
	t_pile	*b;
	
	lst = NULL;
	b = NULL;
	move_list = NULL;
	lst = malloc(sizeof(lst));
	lst->a = nb_to_sort;
	lst->b = b;
	lst->move_list = move_list;
	print_list(lst->a, 2);
	if (lst->a->next == NULL)
		return ;
	else
	{
		if (check_if_sorted(lst->a) == 1)
		{
			if (size == 2)
			{
				lst = swap_a(lst);
				print_list_move(lst->move_list);
			}
			else if (size == 3)
				lst = sort_with_three(lst);
			else if (size == 5)
				lst = sort_with_five(lst);
			else
				lst = sort_big_lists(lst);
		}
	}
	free_list(lst->b);
	free_list(lst->a);
}
