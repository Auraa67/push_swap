/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:24:01 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 11:18:22 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node *stack_a, t_stack_node *stack_b, int min_a)
{
	if (size_stack(stack_a) == 2)
		sort_min(&stack_a);
	else if (size_stack(stack_a) == 3)
	{
		sort_three(&stack_a);
	}
	else if (size_stack(stack_a) == 4)
	{
		sort_four(&stack_a, &stack_b);
	}
	else if (size_stack(stack_a) > 4)
	{
		if (size_stack(stack_a) >= 5)
			multiple_exec(&stack_a, &stack_b, 2, "pb");
		first_step(&stack_a, &stack_b);
		second_step(&stack_a, &stack_b);
		back_up_top(&stack_a, min_a);
	}
	ft_stackclear(&stack_a);
	return ;
}

t_stack_node	*info_min(t_stack_node	*a, int min_a)
{
	t_stack_node	*temp;

	temp = a;
	while (temp->value != min_a)
	{
		temp = temp->next;
	}
	return (temp);
}

void	back_up_top(t_stack_node **stack_a, int min_a)
{
	t_stack_node	*temp;

	if (!stack_a)
		return ;
	while ((*stack_a)->value != min_a && (*stack_a)->index == 0)
	{
		init_median(stack_a);
		temp = info_min(*stack_a, min_a);
		if (ft_strcmp(temp->median, "up") == 0)
		{
			rotate_a(stack_a, "ra");
		}
		else
			reverse_rotate_a(stack_a, "rra");
	}
}

static void	ft_stackdelone(t_stack_node *stack)
{
	if (!stack)
		return ;
	free(stack);
}

void	ft_stackclear(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = (*stack);
	while (current)
	{
		temp = current->next;
		current->value = 0;
		ft_stackdelone(current);
		current = temp;
	}
	*stack = NULL;
}
