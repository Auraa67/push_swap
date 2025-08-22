/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:58:51 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 12:12:48 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_top(t_stack_node **stack, t_stack_node *cheap, char *name)
{
	while (*stack != cheap)
	{
		if (ft_strcmp(name, "stack_a") == 0)
		{
			if (ft_strcmp(cheap->median, "up") == 0)
			{
				rotate_a(stack, "ra");
			}
			else if (ft_strcmp(cheap->median, "down") == 0)
				reverse_rotate_a(stack, "rra");
		}
		else if (ft_strcmp(name, "stack_b") == 0)
		{
			if (ft_strcmp(cheap->median, "up") == 0)
			{
				rotate_b(stack, "rb");
			}
			else if (ft_strcmp(cheap->median, "down") == 0)
				reverse_rotate_b(stack, "rrb");
		}
	}
}

static void	a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_cheap;

	node_cheap = retrieve_cheap(*a);
	if (ft_strcmp(node_cheap->median, "up") == 0
		&& ft_strcmp(node_cheap->target_node->median, "up") == 0)
	{
		while (node_cheap->index != 0
			&& node_cheap->target_node->index != 0)
		{
			simple_exec(a, b, "rr");
		}
	}
	else if (ft_strcmp(node_cheap->median, "down") == 0
		&& ft_strcmp(node_cheap->target_node->median, "down") == 0)
	{
		while (node_cheap->index != 0
			&& node_cheap->target_node->index != 0)
		{
			simple_exec(a, b, "rrr");
		}
	}
	check_top(a, node_cheap, "stack_a");
	check_top(b, node_cheap->target_node, "stack_b");
	simple_exec(a, b, "pb");
}

static void	init_a_b(t_stack_node **a, t_stack_node **b)
{
	init_index(a);
	init_index(b);
	init_median(a);
	init_median(b);
	find_target_of_a(a, b);
	cost_calculus(a, *b);
	is_cheapest(b);
}

void	first_step(t_stack_node **a, t_stack_node **b)
{
	while (size_stack(*a) > 3)
	{
		init_a_b(a, b);
		a_to_b(a, b);
	}
	sort_three(a);
}
