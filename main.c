/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:04 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/01 13:04:09 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_array(int	*array, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[min] > array[j])
				min = j;
			j++;
		}
		if (min != i)
			ft_swap(&array[min], &array[i]);
		i++;
	}
	return (array);
}

static int	get_index(int *array, int nb, int size)
{
	int	index;
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == nb)
			index = i;
		i++;
	}
	return (index);
}

static t_pile	*add_index_list(t_pile *nb_to_sort, int *array, int size)
{
	int		index;
	t_pile	*tmp;

	tmp = nb_to_sort;
	while (tmp != NULL && array)
	{
		index = get_index(array, tmp->nb, size);
		tmp->index = index;
		tmp = tmp->next;
	}
	return (nb_to_sort);
}

static int	*fill_array(int *array, t_pile **nb_to_sort, int size)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = *nb_to_sort;
	while (tmp != NULL && i < size)
	{
		array[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	return (array);
}

int	main(int ac, char **av)
{
	t_pile	*nb_to_sort;
	int		*array;
	int		size;

	nb_to_sort = parse_check(ac, av);
	if (nb_to_sort == NULL)
		return (EXIT_FAILURE);
	size = ft_lst_size(nb_to_sort);
	array = malloc(sizeof(int) * size);
	array = fill_array(array, &nb_to_sort, size);
	array = sort_array(array, size);
	nb_to_sort = add_index_list(nb_to_sort, array, size);
	push_swap(nb_to_sort, size);
	free(array);
	return (EXIT_SUCCESS);
}
