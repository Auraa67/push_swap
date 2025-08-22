/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:31:50 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 11:26:50 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	search_near_max(int b, t_stack_node *stack_a)
{
	t_stack_node	*a;
	int				value;
	int				min;

	if (!stack_a)
		return (0);
	a = stack_a;
	value = 2147483647;
	min = get_min(stack_a, size_stack(stack_a), "value");
	while (a)
	{
		if (a->value > b && a->value < value)
		{
			value = a->value;
		}
		a = a->next;
	}
	if (value == 2147483647)
	{
		value = min;
	}
	return (value);
}

void	find_target_of_b(t_stack_node **stack_b, t_stack_node **stack_a)
{
	t_stack_node	*temp_b;
	t_stack_node	*temp_a;
	int				max_a_for_b;

	temp_b = (*stack_b);
	max_a_for_b = 0;
	while (*stack_b)
	{
		temp_a = (*stack_a);
		max_a_for_b = search_near_max((*stack_b)->value, temp_a);
		while (temp_a)
		{
			if (temp_a->value == max_a_for_b)
			{
				(*stack_b)->target_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = temp_b;
}

t_stack_node	*retrieve_target_b(t_stack_node *stack_b, t_stack_node *stack_a)
{
	t_stack_node	*temp;

	temp = stack_a;
	while (temp)
	{
		if (stack_b->target_node->value == temp->value)
		{
			return (temp);
		}
		temp = temp->next;
	}
	return (0);
}

void	raise_target(t_stack_node **stack, t_stack_node *cheap, char *name)
{
	while (*stack != cheap)
	{
		if (ft_strcmp(name, "stack_a") == 0)
		{
			if (ft_strcmp(cheap->median, "up") == 0 && cheap->index != 0)
			{
				rotate_a(stack, "ra");
			}
			else if (ft_strcmp(cheap->median, "down") == 0 && cheap->index != 0)
				reverse_rotate_a(stack, "rra");
			else
				return ;
		}
	}
}
