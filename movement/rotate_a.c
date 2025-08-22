/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:45 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/05 14:42:56 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack_node **stack_a, char *return_type)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack_a || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	if (ft_strcmp(return_type, "ra") != 0)
		return ;
	first = (*stack_a);
	last = (*stack_a);
	while (last->next != NULL)
		last = last->next;
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	init_index(stack_a);
	write(1, "ra\n", 3);
}
