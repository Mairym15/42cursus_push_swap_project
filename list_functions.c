/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:37:29 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/25 21:34:18 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_lst_new(int nb)
{
	t_pile	*new_lst;

	new_lst = malloc(sizeof(t_pile));
	if (!new_lst)
		return (NULL);
	new_lst->nb = nb;
	new_lst->next = NULL;
	return (new_lst);
}

void	ft_lst_add_back(t_pile **lst, t_pile *new)
{
	t_pile	*tmp;

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

void	print_list(t_pile *nb_to_sort, int bool)
{
	t_pile	*tmp;

	tmp = nb_to_sort;
	while (tmp != NULL)
	{
		if (bool == 0)
			ft_printf("%d\n", tmp->nb);
		else if (bool == 1)
			ft_printf("%d - %d\n", tmp->nb, tmp->index);
		else
			ft_printf("%d\n", tmp->index);
		tmp = tmp->next;
	}
}

t_pile	*ft_lst_last(t_pile *lst)
{
	if (lst == NULL)
		return (0);
	if (lst->next == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lst_size(t_pile *lst)
{
	int		i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i + 1);
}
