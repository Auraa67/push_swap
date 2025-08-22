/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:38 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/05 14:42:21 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_stack_node **stack_a, char *return_type)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*temp;

	if (!stack_a || (*stack_a) == NULL)
		return ;
	if (ft_strcmp(return_type, "rra") != 0)
		return ;
	first = (*stack_a);
	last = (*stack_a);
	while (last->next != NULL)
		last = last->next;
	temp = last;
	last->prev->next = NULL;
	first->prev = temp;
	temp->next = first;
	temp->prev = NULL;
	(*stack_a) = temp;
	init_index(stack_a);
	write(1, "rra\n", 4);
}
