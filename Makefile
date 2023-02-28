# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 10:15:55 by mkerkeni          #+#    #+#              #
#    Updated: 2023/02/28 11:30:34 by mkerkeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = Libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CHECKER_NAME = checker
CHECKER_FOLDER = checker/

SRCS = push_swap.c ft_push.c ft_reverse_rotate.c ft_rotate.c ft_swap.c \
 list_functions.c main.c parse_check.c push_swap_utils.c sort_big_lists.c \
 sort_big_lists_2.c sort_big_lists_3.c get_max.c create_lst_move.c \

SRCS_BONUS = checker.c ft_push_bonus.c ft_swap_bonus.c ft_rotate_bonus.c \
ft_reverse_rotate_bonus.c parse_check_bonus.c push_swap_utils.c list_functions.c \

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
