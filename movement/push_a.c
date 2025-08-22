/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:32 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/05 14:41:14 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack_node **a, t_stack_node **b, char *return_type)
{
	t_stack_node	*temp;

	if (!a || !b || (*b) == NULL)
		return ;
	if (ft_strcmp(return_type, "pa") != 0)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = (*a);
	if (*a)
		(*a)->prev = temp;
	temp->prev = NULL;
	(*a) = temp;
	init_index(a);
	init_index(b);
	init_median(a);
	init_median(b);
	write(1, "pa\n", 3);
}
