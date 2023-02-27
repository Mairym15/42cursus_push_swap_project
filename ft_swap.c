/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:57:27 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/27 14:36:13 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_lst *lst)
{
	t_pile	*tmp;
	t_move	*next;

	if (lst->a->next == NULL)
		ft_printf("liste pas vide\n");
	if (lst->a != NULL && lst->a->next != NULL)
	{
		tmp = lst->a;
		lst->a = lst->a->next;
		tmp->next = lst->a->next;
		lst->a->next = tmp;
		next = ft_lstnew_move("sa\n");
		ft_lstadd_back_move(&(lst->move_list), next);
	}
}

void	swap_b(t_lst *lst)
{
	t_pile	*tmp;
	t_move	*next;

	if (lst->b != NULL && lst->b->next != NULL)
	{
		tmp = lst->b;
		lst->b = lst->b->next;
		tmp->next = lst->b->next;
		lst->b->next = tmp;
		next = ft_lstnew_move("sb\n");
		ft_lstadd_back_move(&(lst->move_list), next);
	}
}

void	swap_a_and_b(t_lst *lst)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;
	t_move	*next;

	if (lst->a != NULL && lst->b != NULL && lst->a->next != NULL
		&& lst->b->next != NULL)
	{
		tmp_a = lst->a;
		lst->a = lst->a->next;
		tmp_a->next = lst->a->next;
		lst->a->next = tmp_a;
		tmp_b = lst->b;
		lst->b = lst->b->next;
		tmp_b->next = lst->b->next;
		lst->b->next = tmp_b;
		next = ft_lstnew_move("ss\n");
		ft_lstadd_back_move(&(lst->move_list), next);
	}
}
