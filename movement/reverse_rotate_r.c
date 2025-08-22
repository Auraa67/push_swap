/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:43 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 12:11:40 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*temp;

	if (!stack || (*stack) == NULL)
		return ;
	first = (*stack);
	last = (*stack);
	while (last->next != NULL)
		last = last->next;
	temp = last;
	last->prev->next = NULL;
	first->prev = temp;
	temp->next = first;
	temp->prev = NULL;
	(*stack) = temp;
	return ;
}

void	reverse_rotate_r(t_stack_node **stack_a, t_stack_node **stack_b,
char *return_type)
{
	if (!stack_a || !stack_b || ft_strcmp(return_type, "rrr") != 0)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	init_index(stack_a);
	init_index(stack_b);
	write(1, "rrr\n", 4);
}
