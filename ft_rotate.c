/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:08:02 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/26 12:12:22 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_lst *lst)
{
	t_pile	*tmp;
	t_move	*next;

	tmp = lst->a;
	if (lst->a != NULL && lst->a->next != NULL)
	{
		while (lst->a->next != NULL)
			lst->a = lst->a->next;
		lst->a->next = tmp;
		lst->a = tmp->next;
		tmp->next = NULL;
		next = ft_lstnew_move("ra\n");
		ft_lstadd_back_move(&(lst->move_list), next);
	}
}

void	rotate_b(t_lst *lst)
{
	t_pile	*tmp;
	t_move	*next;

	tmp = lst->b;
	if (lst->b != NULL && lst->b->next != NULL)
	{
		while (lst->b->next != NULL)
			lst->b = lst->b->next;
		lst->b->next = tmp;
		lst->b = tmp->next;
		tmp->next = NULL;
		next = ft_lstnew_move("rb\n");
		ft_lstadd_back_move(&(lst->move_list), next);
	}
}

void	rotate_a_and_b(t_lst *lst)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;
	t_move	*next;

	tmp_a = lst->a;
	if (lst->a != NULL && lst->b != NULL && lst->a->next != NULL
		&& lst->b->next != NULL)
	{
		while (lst->a->next != NULL)
			lst->a = lst->a->next;
		lst->a->next = tmp_a;
		lst->a = tmp_a->next;
		tmp_a->next = NULL;
		tmp_b = lst->b;
		while (lst->b->next != NULL)
			lst->b = lst->b->next;
		lst->b->next = tmp_b;
		lst->b = tmp_b->next;
		tmp_b->next = NULL;
		next = ft_lstnew_move("rr\n");
		ft_lstadd_back_move(&(lst->move_list), next);
	}
}
