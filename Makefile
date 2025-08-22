# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:24:57 by merazafi          #+#    #+#              #
#    Updated: 2025/07/30 08:54:51 by merazafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c\
	push_swap.c\
	init_utils.c\
	init_stack.c\
	push_swap_utils.c\
	one_params_converter.c\
	check_condition.c\
	sort_number/calculus.c\
	sort_number/first_step.c\
	sort_number/second_step_utils.c\
	sort_number/sort_min.c\
	sort_number/second_step.c\
	sort_number/sort_utils.c\
	movement/push_a.c\
	movement/push_b.c\
	movement/reverse_rotate_a.c\
	movement/reverse_rotate_b.c\
	movement/reverse_rotate_r.c\
	movement/rotate_a.c\
	movement/rotate_b.c\
	movement/rotate_r.c\
	movement/swap_a.c\
	movement/swap_b.c\
	movement/swap_ss.c\
	params_utils.c\

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
