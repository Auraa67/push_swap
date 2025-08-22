/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:54 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/05 14:43:32 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack_node **stack_a, char *return_type)
{
	int	temp;

	if (!stack_a || (*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	if (ft_strcmp(return_type, "sa") != 0)
		return ;
	temp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = temp;
	init_index(stack_a);
	write(1, "sa\n", 3);
}
