/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:40 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/06 10:37:46 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_b(t_stack_node **stack_b, char *return_type)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*temp;

	if (!stack_b || (*stack_b) == NULL)
		return ;
	if (ft_strcmp(return_type, "rrb") != 0)
		return ;
	first = (*stack_b);
	last = (*stack_b);
	while (last->next != NULL)
		last = last->next;
	temp = last;
	last->prev->next = NULL;
	first->prev = temp;
	temp->next = first;
	temp->prev = NULL;
	(*stack_b) = temp;
	init_index(stack_b);
	write(1, "rrb\n", 4);
}
