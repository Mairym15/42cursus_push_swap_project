/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:20:38 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/27 16:44:09 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_if_sorted(t_pile *a)
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

static t_pile	*make_moves(t_pile **a, t_pile **b, char *line)
{
	if (line == "pa\n")
		push_a_bonus(a, b);
	else if (line == "pb\n")
		push_b_bonus(a, b);
	else if (line == "sa\n")
		swap_a_bonus(a);
	else if (line == "sb\n")
		swap_b_bonus(b);
	else if (line == "ss")
		swap_a_and_b_bonus(a, b);
	else if (line == "ra\n")
		rotate_a_bonus(a);
	else if (line == "rb\n")
		rotate_b_bonus(b);
	else if (line == "rr\n")
		rotate_a_and_b_bonus(a, b);
	else if (line == "rra\n")
		reverse_rotate_a_bonus(a);
	else if (line == "rrb\n")
		reverse_rotate_b_bonus(b);
	else if (line == "rrr\n")
		reverse_rotate_a_and_b_bonus(a, b);
	return (*a);
}

static int	check_instruction(t_pile *a)
{
	char	*line;
	t_pile	*b;
	
	b = NULL;
	while (get_next_line(0) > 0)
	{
		line = get_next_line(0);
		if (line != "pa\n" && line != "sa\n" && line != "pb\n" && line != "sb\n"
			&& line != "ss\n" && line != "ra\n" && line != "rb\n"
			&& line != "rr\n" && line != "rra\n" && line != "rrb\n" 
			&& line != "rrr\n")
		{
			ft_printf("Error\n");
			return (EXIT_FAILURE);
		}
		else
		{
			a = make_moves(&a, &b, line);
			if (check_if_sorted(a) == 0)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_pile	*nb_to_sort;
	
	if (ac < 2)
		return (EXIT_SUCCESS);
	nb_to_sort = parse_check(ac, av);
	if (nb_to_sort == NULL)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	check_instruction(nb_to_sort);
	return (EXIT_SUCCESS);
}
