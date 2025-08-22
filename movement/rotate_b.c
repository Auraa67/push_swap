/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:48 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/05 14:43:09 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_b(t_stack_node **stack_b, char *return_type)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack_b || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	if (ft_strcmp(return_type, "rb") != 0)
		return ;
	first = (*stack_b);
	last = (*stack_b);
	while (last->next != NULL)
		last = last->next;
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	init_index(stack_b);
	write(1, "rb\n", 3);
}
