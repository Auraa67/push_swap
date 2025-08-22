/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 07:45:48 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/06 11:20:18 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max(t_stack_node *stack, int size, char *return_type)
{
	int				value;
	t_stack_node	*temp;
	int				i;
	int				index;

	if (!stack)
		return (0);
	i = -1;
	index = 0;
	temp = stack;
	value = stack->value;
	while (++i < size)
	{
		if (temp->value > value)
		{
			value = temp->value;
			index = i;
		}
		temp = temp->next;
	}
	if (ft_strcmp(return_type, "index") == 0)
		return (index);
	else if (ft_strcmp(return_type, "value") == 0)
		return (value);
	return (-1);
}

int	get_min(t_stack_node *stack, int size, char *return_type)
{
	int				value;
	t_stack_node	*temp;
	int				i;
	int				index;

	if (!stack)
		return (0);
	i = -1;
	index = 0;
	temp = stack;
	value = stack->value;
	while (++i < size)
	{
		if (temp->value < value)
		{
			value = temp->value;
			index = i;
		}
		temp = temp->next;
	}
	if (ft_strcmp(return_type, "index") == 0)
		return (index);
	else if (ft_strcmp(return_type, "value") == 0)
		return (value);
	return (-1);
}

t_stack_node	*last_first_node(t_stack_node *stack, char *return_type)
{
	if (!stack)
		return (NULL);
	if (ft_strcmp(return_type, "first") == 0)
	{
		while (stack->prev)
			stack = stack->prev;
		return (stack);
	}
	else if (ft_strcmp(return_type, "last") == 0)
	{
		while (stack->next)
			stack = stack->next;
		return (stack);
	}
	return (0);
}
