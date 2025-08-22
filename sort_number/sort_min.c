/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:45:06 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 10:08:13 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_min(t_stack_node **a)
{
	int	top;
	int	bottom;

	if (!a || !(*a) || !(*a)->next)
		return ;
	top = (*a)->value;
	bottom = (*a)->next->value;
	if (top > bottom)
		swap_a(a, "sa");
	return ;
}

void	sort_three_pt2(t_stack_node **a, int top, int mid, int bottom)
{
	if (top < mid && mid > bottom && top > bottom)
		reverse_rotate_a(a, "rra");
	else if (top > mid && mid < bottom && top > bottom)
		rotate_a(a, "ra");
	else if (top > mid && mid > bottom && top > bottom)
	{
		write(1, "sa\n", 3);
		swap(a);
		reverse_rotate_a(a, "rra");
	}
}

void	sort_three(t_stack_node **a)
{
	int	top;
	int	mid;
	int	bottom;

	if (!a || !(*a) || !(*a)->next || !(*a)->next->next)
		return ;
	top = (*a)->value;
	mid = (*a)->next->value;
	bottom = (*a)->next->next->value;
	if (top < mid && mid > bottom && top < bottom)
	{
		write(1, "sa\n", 3);
		swap(a);
		rotate_a(a, "ra");
	}
	else if (top > mid && mid < bottom && top < bottom)
	{
		write(1, "sa\n", 3);
		swap(a);
	}
	else
		sort_three_pt2(a, top, mid, bottom);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	int				min_value;
	int				size;

	if (!a || !b)
		return ;
	size = size_stack(*a);
	min_value = get_min((*a), size, "value");
	back_up_top(a, min_value);
	push_b(a, b, "pb");
	sort_three(a);
	push_a(a, b, "pa");
}
