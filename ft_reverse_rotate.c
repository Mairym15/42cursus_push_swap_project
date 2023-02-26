/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:04:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/25 22:44:34 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*reverse_rotate_a(t_lst *lst)
{
	t_pile	*current;
	t_pile	*tmp;
	t_pile	*last;
	t_move	*next;

	tmp = lst->a;
	last = lst->a;
	current = (lst->a)->next;
	while ((last->next)->next != NULL)
		last = last->next;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	lst->a = current;
	last->next = NULL;
	next = ft_lstnew_move("rra\n");
	ft_lstadd_back_move(&lst->move_list, next);
	return (lst);
}

t_lst	*reverse_rotate_b(t_lst *lst)
{
	t_pile	*current;
	t_pile	*tmp;
	t_pile	*last;
	t_move	*next;

	tmp = lst->b;
	last = lst->b;
	current = (lst->b)->next;
	while ((last->next)->next != NULL)
		last = last->next;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	lst->b = current;
	last->next = NULL;
	next = ft_lstnew_move("rrb\n");
	ft_lstadd_back_move(&lst->move_list, next);
	return (lst);
}

t_lst	*reverse_rotate_a_and_b(t_lst *lst)
{
	t_move	*next;
	
	lst = reverse_rotate_a(lst);
	lst = reverse_rotate_b(lst);
	next = ft_lstnew_move("rrr\n");
	ft_lstadd_back_move(&lst->move_list, next);
	return (lst);
}
