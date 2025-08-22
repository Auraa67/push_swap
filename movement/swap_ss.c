/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:59 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/06 10:38:26 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack_node **stack)
{
	int	temp;

	if (!stack || (*stack) == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	swap_ss(t_stack_node **stack_a, t_stack_node **stack_b,
char *return_type)
{
	if (!stack_a || !stack_b || ft_strcmp(return_type, "ss") != 0)
		return ;
	swap(stack_a);
	swap(stack_b);
	init_index(stack_a);
	init_index(stack_b);
	write(1, "ss\n", 3);
}
