/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:29:06 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/25 21:56:17 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_pile
{
	int				nb;
	int				index;
	struct s_pile	*next;
}	t_pile;

typedef struct s_move
{
	char			*move;
	struct s_move	*next;
}	t_move;

typedef struct s_lst
{
	t_pile	*a;
	t_pile	*b;
	t_move	*move_list;	
}	t_lst;

typedef struct s_var {
	int		closest_a;
	int		best_a;
	int		best_b;
	int		max_a;
	int		sec_max_a;
	int		thir_max_a;
}	t_var;

int			main(int ac, char **av);

t_pile		*parse_check(int ac, char **av);

void		push_swap(t_pile *list, int size);
int			check_if_sorted(t_pile *a);
t_lst		*sort_with_three(t_lst *lst);

t_lst		*sort_big_lists(t_lst *lst);
t_lst		*sort_list(t_lst *lst, t_var v, int move);

int			get_max(t_pile **lst);
int			get_second_max(t_pile **lst);
int			get_third_max(t_pile **lst);

t_pile		*get_middle(t_pile	**lst);
int			check_position(t_pile **lst, int value, t_pile	*middle);
int			get_number_of_move(t_pile **lst, int value);

t_lst		*match_best_values(t_lst *lst, int val_a, int val_b);
int			get_closest_nb(t_pile **lst, int value, int max);

t_lst		*swap_a(t_lst *lst);
t_lst		*swap_b(t_lst *lst);
t_lst		*swap_a_and_b(t_lst *lst);

t_lst		*push_a(t_lst *lst);
t_lst		*push_b(t_lst *lst);

t_lst		*rotate_a(t_lst *lst);
t_lst		*rotate_b(t_lst *lst);
t_lst		*rotate_a_and_b(t_lst *lst);

t_lst		*reverse_rotate_a(t_lst *lst);
t_lst		*reverse_rotate_b(t_lst *lst);
t_lst		*reverse_rotate_a_and_b(t_lst *lst);

t_pile		*ft_lst_new(int nb);
void		ft_lst_add_back(t_pile **lst, t_pile *new);
t_pile		*ft_lst_last(t_pile *lst);
int			ft_lst_size(t_pile *lst);
void		print_list(t_pile *nb_to_sort, int bool);

void		print_list_move(t_move *list_move);
void		ft_lstadd_back_move(t_move **lst, t_move *new);
t_move		*ft_lstnew_move(char *move);

long int	ft_atol(const char *str);
void		ft_swap(int *a, int *b);
void		free_list(t_pile *lst);

#endif