/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:56 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/05 14:43:44 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_b(t_stack_node **stack_b, char *return_type)
{
	int	temp;

	if (!stack_b || (*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	if (ft_strcmp(return_type, "sb") != 0)
		return ;
	temp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = temp;
	init_index(stack_b);
	write(1, "sb\n", 3);
}
