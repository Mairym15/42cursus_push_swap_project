/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:29:06 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/01 10:37:12 by mkerkeni         ###   ########.fr       */
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
void		sort_with_three(t_lst *lst);

void		sort_big_lists(t_lst *lst);
void		sort_list(t_lst *lst, t_var v, int move);

void		sort_medium_lists(t_lst *lst);

int			get_max(t_pile **lst);
int			get_second_max(t_pile **lst);
int			get_third_max(t_pile **lst);

t_pile		*get_middle(t_pile	*lst);
int			check_position(t_pile *lst, int value);
int			get_number_of_move(t_pile *lst, int value);

void		match_best_values(t_lst *lst, int val_a, int val_b);
int			get_closest_nb(t_pile *lst, int value, int max);

void		swap_a(t_lst *lst);
void		swap_b(t_lst *lst);
void		swap_a_and_b(t_lst *lst);

void		push_a(t_lst *lst);
void		push_b(t_lst *lst);

void		rotate_a(t_lst *lst);
void		rotate_b(t_lst *lst);
void		rotate_a_and_b(t_lst *lst);

void		reverse_rotate_a(t_lst *lst, int bool);
void		reverse_rotate_b(t_lst *lst, int bool);
void		reverse_rotate_a_and_b(t_lst *lst);

t_pile		*ft_lst_new(int nb);
void		ft_lst_add_back(t_pile **lst, t_pile *new);
t_pile		*ft_lst_last(t_pile *lst);
int			ft_lst_size(t_pile *lst);
void		print_list(t_pile *nb_to_sort, int bool);

void		print_list_move(t_move *list_move);
void		ft_lstadd_back_move(t_move **lst, t_move *new);
t_move		*ft_lstnew_move(char *move);
int			ft_lstsize_move(t_move *list_move);
void		free_list_move(t_move *lst);

long int	ft_atol(const char *str);
void		ft_swap(int *a, int *b);
void		free_list(t_pile *lst);

#endif