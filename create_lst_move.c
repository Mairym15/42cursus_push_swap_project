/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:35:19 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/26 12:26:25 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*ft_lstnew_move(char *move)
{
	t_move	*new_lst;

	new_lst = malloc(sizeof(t_move));
	if (!new_lst)
		return (NULL);
	new_lst->move = move;
	new_lst->next = NULL;
	return (new_lst);
}

void	ft_lstadd_back_move(t_move **lst, t_move *new)
{
	t_move	*tmp;

	if (*lst == NULL)
	{	
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	print_list_move(t_move *list_move)
{
	t_move	*tmp;

	tmp = list_move;
	while (tmp != NULL)
	{
		ft_printf("%s", tmp->move);
		tmp = tmp->next;
	}	
}
