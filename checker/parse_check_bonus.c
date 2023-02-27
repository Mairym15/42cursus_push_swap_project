/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:47:07 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/27 16:46:41 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_doublon(t_pile *nb_to_sort)
{
	t_pile	*tmp;
	int		data;

	tmp = nb_to_sort;
	nb_to_sort = nb_to_sort->next;
	while (tmp != NULL)
	{
		data = tmp->nb;
		nb_to_sort = tmp->next;
		while (nb_to_sort != NULL)
		{
			if (nb_to_sort->nb == data)
				return (0);
			nb_to_sort = nb_to_sort->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	check_if_nb(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '-' || str[j] == '+')
			j++;
		if (str[j] < '0' || str[j] > '9')
		{
			if (str[j] != ' ')
				return (0);
		}
		j++;
	}
	return (1);
}

static t_pile	*get_list(t_pile *nb_to_sort, char *arg)
{
	t_pile	*next;
	char	**tmp;
	int		i;

	if (!ft_strchr(arg, ' '))
	{
		next = ft_lst_new(ft_atol(arg));
		ft_lst_add_back(&nb_to_sort, next);
	}
	else
	{
		tmp = ft_split(arg, ' ');
		i = 0;
		while (tmp[i])
		{
			next = ft_lst_new(ft_atol(tmp[i]));
			ft_lst_add_back(&nb_to_sort, next);
			i++;
		}
	}
	return (nb_to_sort);
}

static t_pile	*display_error(void)
{
	write(2, "Error\n", 6);
	return (NULL);
}

t_pile	*parse_check_bonus(int ac, char **av)
{
	int		i;
	t_pile	*nb_to_sort;

	i = 1;
	nb_to_sort = NULL;
	if (ac < 2)
		return (NULL);
	while (i < ac)
	{
		if (check_if_nb(av[i]) == 0 || ft_atol(av[i]) < INT_MIN
			|| ft_atol(av[i]) > INT_MAX)
			return (display_error());
		nb_to_sort = get_list(nb_to_sort, av[i]);
		i++;
	}
	if (check_doublon(nb_to_sort) == 0)
	{
		free_list(nb_to_sort);
		return (display_error());
	}
	return (nb_to_sort);
}
