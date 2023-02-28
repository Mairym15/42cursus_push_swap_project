/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:20:38 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/28 16:08:59 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_if_sorted_bonus(t_pile *a)
{
	t_pile	*tmp;

	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->nb < (tmp->next)->nb)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

static int	read_instructions(t_pile **a, t_pile **b, char *line)
{
	while (line > 0)
	{
		if (!ft_strncmp(line, "pa\n", 3))
			push_a_bonus(a, b);
		else if (!ft_strncmp(line, "pb\n", 3))
			push_b_bonus(a, b);
		else if (!ft_strncmp(line, "sa\n", 3))
			swap_a_bonus(a);
		else if (!ft_strncmp(line, "sb\n", 3))
			swap_b_bonus(b);
		else if (!ft_strncmp(line, "ss\n", 3))
			swap_a_and_b_bonus(a, b);
		else if (!ft_strncmp(line, "ra\n", 3))
			rotate_a_bonus(a);
		else if (!ft_strncmp(line, "rb\n", 3))
			rotate_b_bonus(b);
		else if (!ft_strncmp(line, "rr\n", 3))
			rotate_a_and_b_bonus(a, b);
		else if (!ft_strncmp(line, "rra\n", 4))
			reverse_rotate_a_bonus(a);
		else if (!ft_strncmp(line, "rrb\n", 4))
			reverse_rotate_b_bonus(b);
		else if (!ft_strncmp(line, "rrr\n", 4))
			reverse_rotate_a_and_b_bonus(a, b);
		else
			return (0);
		line = get_next_line(0);
	}
	return (1);
}

static int	check_instruction(t_pile *a)
{
	t_pile	*b;
	char	*line;

	b = NULL;
	line = get_next_line(0);
	if (read_instructions(&a, &b, line) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
	{
		if (check_if_sorted_bonus(a) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_pile	*nb_to_sort;

	if (ac < 2)
		return (EXIT_SUCCESS);
	nb_to_sort = parse_check_bonus(ac, av);
	if (nb_to_sort == NULL)
		return (EXIT_FAILURE);
	if (check_instruction(nb_to_sort) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
