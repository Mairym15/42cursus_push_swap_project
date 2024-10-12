# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 10:15:55 by mkerkeni          #+#    #+#              #
#    Updated: 2024/10/12 22:15:36 by mkerkeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = Libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CHECKER_NAME = checker

SRCS =	srcs/push_swap.c \
		srcs/ft_push.c \
		srcs/ft_reverse_rotate.c \
		srcs/ft_rotate.c \
		srcs/ft_swap.c \
		srcs/list_functions.c \
		srcs/main.c \
		srcs/parse_check.c \
		srcs/push_swap_utils.c \
		srcs/sort_big_lists.c \
		srcs/sort_big_lists_2.c \
		srcs/sort_big_lists_3.c \
		srcs/get_max.c \
		srcs/create_lst_move.c \
		srcs/sort_medium_lists.c

SRCS_BONUS =	my_checker/checker.c \
				my_checker/ft_push_bonus.c \
				my_checker/ft_swap_bonus.c \
				my_checker/ft_rotate_bonus.c \
				my_checker/ft_reverse_rotate_bonus.c \
				my_checker/parse_check_bonus.c \
				srcs/push_swap_utils.c \
				srcs/list_functions.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(CHECKER_NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT)libft.a

$(CHECKER_NAME): $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(CHECKER_NAME) $^ $(LIBFT)libft.a

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER_NAME)
	rm -f Libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus
