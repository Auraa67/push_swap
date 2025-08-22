/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:35 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/05 14:41:36 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_stack_node **a, t_stack_node **b, char *return_type)
{
	t_stack_node	*temp;

	if (!a || !b || (*a) == NULL)
		return ;
	if (ft_strcmp(return_type, "pb") != 0)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = (*b);
	if (*b)
		(*b)->prev = temp;
	temp->prev = NULL;
	(*b) = temp;
	init_index(a);
	init_index(b);
	init_median(a);
	init_median(b);
	write(1, "pb\n", 3);
}
