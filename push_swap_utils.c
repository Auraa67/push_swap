/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:11:45 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/10 09:53:20 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	size_stack(t_stack_node *stack)
{
	t_stack_node	*temp;
	int				count;

	count = 0;
	if (!stack)
		return (0);
	temp = last_first_node(stack, "first");
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	simple_exec(t_stack_node **stack_a, t_stack_node **stack_b,
char *operation)
{
	if (!stack_a || !stack_b || !operation)
		return ;
	if (ft_strcmp(operation, "pa") == 0)
		return (push_a(stack_a, stack_b, "pa"));
	else if (ft_strcmp(operation, "pb") == 0)
		return (push_b(stack_a, stack_b, "pb"));
	else if (ft_strcmp(operation, "rra") == 0)
		return (reverse_rotate_a(stack_a, "rra"));
	else if (ft_strcmp(operation, "rrb") == 0)
		return (reverse_rotate_b(stack_b, "rrb"));
	else if (ft_strcmp(operation, "rrr") == 0)
		return (reverse_rotate_r(stack_a, stack_b, "rrr"));
	else if (ft_strcmp(operation, "ra") == 0)
		return (rotate_a(stack_a, "ra"));
	else if (ft_strcmp(operation, "rb") == 0)
		return (rotate_b(stack_b, "rb"));
	else if (ft_strcmp(operation, "rr") == 0)
		return (rotate_r(stack_a, stack_b, "rr"));
	else if (ft_strcmp(operation, "sa") == 0)
		return (swap_a(stack_a, "sa"));
	else if (ft_strcmp(operation, "sb") == 0)
		return (swap_b(stack_b, "sb"));
	else if (ft_strcmp(operation, "ss") == 0)
		return (swap_ss(stack_a, stack_b, "ss"));
}

void	multiple_exec(t_stack_node **stack_a, t_stack_node **stack_b,
int repetition, char *operation)
{
	if (!stack_a || !stack_b || !operation)
		return ;
	while (repetition > 0)
	{
		simple_exec(stack_a, stack_b, operation);
		repetition--;
	}
}
