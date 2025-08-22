/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:31:37 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 11:26:58 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_b_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	init_index(stack_a);
	init_index(stack_b);
	init_median(stack_a);
	init_median(stack_b);
	find_target_of_b(stack_b, stack_a);
}

static void	b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	temp = retrieve_target_b(*b, *a);
	raise_target(a, temp, "stack_a");
	simple_exec(a, b, "pa");
}

void	second_step(t_stack_node **a, t_stack_node **b)
{
	while (*b)
	{
		init_b_a(a, b);
		b_to_a(a, b);
	}
}
