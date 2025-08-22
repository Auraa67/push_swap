/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:50 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/06 11:06:24 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || (*stack) == NULL || (*stack)->next == NULL)
		return ;
	first = (*stack);
	last = (*stack);
	while (last->next != NULL)
		last = last->next;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rotate_r(t_stack_node **stack_a, t_stack_node **stack_b,
char *return_type)
{
	if (!stack_a || !stack_b || ft_strcmp(return_type, "rr") != 0)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	init_index(stack_a);
	init_index(stack_b);
	write(1, "rr\n", 3);
}
