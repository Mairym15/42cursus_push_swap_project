/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_lists_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:45:07 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/26 11:36:09 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_middle(t_pile	*lst)
{
	int		half;
	t_pile	*middle;
	int		i;

	half = ft_lst_size(lst) / 2;
	middle = lst;
	i = 0;
	if (ft_lst_size(lst) % 2 == 0)
	{
		while (i < half)
		{
			middle = middle->next;
			i++;
		}
	}
	else
	{
		while (i <= half)
		{
			middle = middle->next;
			i++;
		}
	}
	return (middle);
}

int	check_position(t_pile *lst, int value, t_pile	*middle)
{
	t_pile	*tmp;

	tmp = lst;
	if (tmp->index == value)
		return (1);
	while (tmp->index != value && tmp != middle)
	{
		tmp = tmp->next;
		if (tmp->index == value)
			return (1);
		if (tmp == middle)
			return (0);
	}
	return (0);
}

static int	nb_of_move_low(t_pile **tmp, int value)
{
	int	move;

	move = 0;
	while ((*tmp)->index != value)
		*tmp = (*tmp)->next;
	while (*tmp != NULL)
	{
		*tmp = (*tmp)->next;
		move++;
	}
	return (move);
}

int	get_number_of_move(t_pile *lst, int value)
{
	int		move;
	t_pile	*tmp;
	t_pile	*middle;

	tmp = lst;
	move = 0;
	middle = get_middle(lst);
	if (check_position(tmp, value, middle) == 1)
	{
		if (tmp->index == value)
			return (0);
		while (tmp->index != value)
		{
			tmp = tmp->next;
			move++;
		}
	}
	else
		move = nb_of_move_low(&tmp, value);
	return (move);
}
