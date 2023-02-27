/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:26:13 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/27 11:44:18 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_pile **lst)
{
	int		max;
	t_pile	*tmp;

	tmp = *lst;
	max = tmp->index;
	while (tmp->next != NULL)
	{
		if (tmp->next->index > max)
			max = tmp->next->index;
		tmp = tmp->next;
	}
	return (max);
}

int	get_second_max(t_pile **lst)
{
	int		sec_max;
	int		max;
	t_pile	*tmp;

	tmp = *lst;
	max = get_max(lst);
	if (tmp->index == max)
		sec_max = tmp->next->index;
	else
		sec_max = tmp->index;
	while (tmp->next != NULL)
	{
		if (tmp->next->index > sec_max && tmp->next->index < max)
			sec_max = tmp->next->index;
		tmp = tmp->next;
	}
	return (sec_max);
}

int	get_third_max(t_pile **lst)
{
	int		sec_max;
	int		thir_max;
	int		max;
	t_pile	*tmp;

	tmp = *lst;
	max = get_max(lst);
	sec_max = get_second_max(lst);
	if (tmp->index == max || tmp->index == sec_max)
	{
		if (tmp->next->index == max || tmp->next->index == sec_max)
			thir_max = tmp->next->next->index;
		else
			thir_max = tmp->next->index;
	}
	else
		thir_max = tmp->index;
	while (tmp->next != NULL)
	{
		if (tmp->next->index > thir_max && tmp->next->index < max
			&& tmp->next->index < sec_max)
			thir_max = tmp->next->index;
		tmp = tmp->next;
	}
	return (thir_max);
}
