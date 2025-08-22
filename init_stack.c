/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:57:08 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 18:00:12 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*ft_new_node(int val)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return_error();
	node->index = -1;
	node->value = val;
	node->cost = 0;
	node->median = NULL;
	node->min_cost = NULL;
	node->target_node = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static void	add_last_back(t_stack_node **stack, t_stack_node *node)
{
	t_stack_node	*temp;

	if (!stack || !node)
		return ;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	node->prev = temp;
	node->next = NULL;
}

static void	add_node(t_stack_node **stack, int val)
{
	t_stack_node	*node;

	node = ft_new_node(val);
	if (!node)
		return ;
	if (*stack == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		*stack = node;
	}
	else
	{
		add_last_back(stack, node);
	}
}

static long	ft_atol(char *argv)
{
	int		i;
	int		sign;
	long	nbr;
	long	result;

	i = 0;
	nbr = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32)
		i++;
	sign = 1;
	if ((argv[i] == '+' || argv[i] == '-'))
	{
		if (argv[i] == '-')
			sign = -sign;
		i++;
	}
	while ((argv[i] >= '0' && argv[i] <= '9'))
	{
		nbr = nbr * 10;
		nbr = nbr + (argv[i] - '0');
		i++;
	}
	result = nbr * sign;
	return (result);
}

void	init_stack(t_stack_node **stack, char *argv[])
{
	long	val;
	int		i;
	int		last;

	i = -1;
	while (argv[++i])
		last = i;
	i = -1;
	if (!stack)
	{
		free(argv);
		return ;
	}
	while (argv[++i])
	{
		val = ft_atol(argv[i]);
		if (val < -2147483648 || val > 2147483647)
			free_argv(argv, stack, i, last);
		else
			add_node(stack, (int)val);
		free(argv[i]);
	}
	free(argv);
	init_index(stack);
	init_median(stack);
}
