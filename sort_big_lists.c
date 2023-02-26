/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:19:09 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/26 13:28:22 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_total_move(t_pile *a, t_pile *b, int value, int closest_a)
{
	int	move;
	int	move_a;
	int	move_b;

	move_a = get_number_of_move(a, closest_a);
	move_b = get_number_of_move(b, value);
	move = move_a + move_b;
	return (move);
}

void	sort_list(t_lst *lst, t_var v, int move)
{
	t_pile	*tmp;
	int		move_next;

	while ((lst->b) != NULL)
	{
		v.closest_a = get_closest_nb(lst->a, lst->b->index, v.max_a);
		move = get_total_move(lst->a, lst->b, lst->b->index, v.closest_a);
		v.best_b = lst->b->index;
		v.best_a = v.closest_a;
		tmp = lst->b->next;
		while (tmp != NULL)
		{
			v.closest_a = get_closest_nb(lst->a, tmp->index, v.max_a);
			move_next = get_total_move(lst->a, lst->b, tmp->index, v.closest_a);
			if (move_next < move)
			{	
				v.best_a = v.closest_a;
				v.best_b = tmp->index;
				move = move_next;
			}
			tmp = tmp->next;
		}
		match_best_values(lst, v.best_a, v.best_b);
	}
}

static void	put_back_in_place_list(t_lst *lst, int bool)
{
	if (bool == 1)
	{
		while (lst->a->index != 0)
			rotate_a(lst);
	}
	else
	{
		while (lst->a->index != 0)
			reverse_rotate_a(lst);
	}
}

static void	fill_b(t_lst *lst, t_var v)
{
	while (lst->a->next->next->next != NULL && lst->a->index != v.max_a
		&& lst->a->index != v.sec_max_a && lst->a->index != v.thir_max_a)
	{
		/*if (lst->b != NULL)
		{
			if (lst->b->index > (ft_lst_size(lst->b) / 2))
				rotate_b(lst);
		}*/
		push_b(lst);
		if (lst->a->next->next->next != NULL && (lst->a->index == v.max_a
				|| lst->a->index == v.sec_max_a
				|| lst->a->index == v.thir_max_a))
		{
			rotate_a(lst);
			if (lst->a->index == v.max_a || lst->a->index == v.sec_max_a
				|| lst->a->index == v.thir_max_a)
				rotate_a(lst);
		}
	}
}

void	sort_big_lists(t_lst *lst)
{
	t_var	v;
	int		move;
	t_pile	*middle;

	v.max_a = get_max(&(lst->a));
	v.sec_max_a = get_second_max(&(lst->a));
	v.thir_max_a = get_third_max(&(lst->a));
	//ft_printf("max a: %d\n", v.max_a);
	//ft_printf("second max a: %d\n", v.sec_max_a);
	//ft_printf("third max a: %d\n", v.thir_max_a);
	move = 0;
	while (lst->a->index == v.max_a || lst->a->index == v.sec_max_a
		|| lst->a->index == v.thir_max_a)
		rotate_a(lst);
	fill_b(lst, v);
	if (check_if_sorted(lst->a) == 1)
		sort_with_three(lst);
	sort_list(lst, v, move);
	middle = get_middle(lst->a);
	if (check_position(lst->a, 0, middle) == 1)
		put_back_in_place_list(lst, 1);
	else
		put_back_in_place_list(lst, 0);
}
