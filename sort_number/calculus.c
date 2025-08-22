/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:57:12 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/31 15:15:30 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	search_near_min(int a, t_stack_node *stack_b)
{
	t_stack_node	*b;
	int				value;
	long			diff;
	int				max;

	if (!stack_b)
		return (0);
	b = stack_b;
	value = 0;
	diff = -2147483648;
	max = get_max(stack_b, size_stack(stack_b), "value");
	while (b)
	{
		if (b->value < a
			&& (long)b->value > diff)
		{
			diff = (long)b->value;
			value = b->value;
		}
		b = b->next;
	}
	if (diff == -2147483648)
		value = max;
	return (value);
}

void	find_target_of_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;
	int				min_a_for_b;

	temp_a = (*stack_a);
	min_a_for_b = 0;
	while (*stack_a)
	{
		temp_b = (*stack_b);
		min_a_for_b = search_near_min((*stack_a)->value, temp_b);
		while (temp_b)
		{
			if (temp_b->value == min_a_for_b)
			{
				(*stack_a)->target_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = temp_a;
}

void	cost_calculus(t_stack_node **stack_a, t_stack_node *stack_b)
{
	int				size_a;
	int				size_b;
	t_stack_node	*temp;

	size_a = size_stack(*stack_a);
	size_b = size_stack(stack_b);
	temp = (*stack_a);
	while (*stack_a)
	{
		(*stack_a)->cost = (*stack_a)->index;
		if (ft_strcmp((*stack_a)->median, "down") == 0)
		{
			(*stack_a)->cost = size_a - ((*stack_a)->index);
		}
		if (ft_strcmp((*stack_a)->target_node->median, "up") == 0)
		{
			(*stack_a)->cost += (*stack_a)->target_node->index;
		}
		else
			(*stack_a)->cost += (size_b - ((*stack_a)->target_node->index));
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = temp;
}

void	is_cheapest(t_stack_node **stack_a)
{
	t_stack_node	*temp;
	int				cheapest;

	if (!(*stack_a) || !stack_a || (*stack_a)->next == NULL)
		return_error();
	temp = *stack_a;
	cheapest = 2147483647;
	while (temp)
	{
		if (temp->cost < cheapest)
			cheapest = temp->cost;
		temp = temp->next;
	}
	temp = *stack_a;
	while ((*stack_a))
	{
		if ((*stack_a)->cost == cheapest)
			(*stack_a)->min_cost = "yes";
		else
			(*stack_a)->min_cost = "no";
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = temp;
}

t_stack_node	*retrieve_cheap(t_stack_node *stack_a)
{
	t_stack_node	*temp;
	int				cheapest;
	t_stack_node	*node;

	if (!stack_a)
		return (0);
	temp = stack_a;
	node = stack_a;
	cheapest = 2147483647;
	while (temp)
	{
		if (temp->cost < cheapest)
			cheapest = temp->cost;
		temp = temp->next;
	}
	while (node)
	{
		if (node->cost == cheapest)
			return (node);
		node = node->next;
	}
	return (node);
}
