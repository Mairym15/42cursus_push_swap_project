/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:09:58 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/27 16:08:48 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_bonus(t_pile *a, t_pile *b)
{
	t_pile	*tmp;
	t_move	*next;

	if (b != NULL)
	{
		tmp = b;
		b = b->next;
		tmp->next = a;
		a = tmp;
	}
}

void	push_b_bonus(t_pile *a, t_pile *b)
{
	t_pile	*tmp;
	t_move	*next;

	if (a != NULL)
	{
		tmp = a;
		a = a->next;
		tmp->next = b;
		b = tmp;
	}
}
