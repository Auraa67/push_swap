/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:22:52 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/16 18:51:40 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stack_node **stack)
{
	int				i;
	t_stack_node	*current;

	current = *stack;
	i = 0;
	if (!stack || !*stack)
		return ;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}

void	init_median(t_stack_node **stack)
{
	t_stack_node	*current;
	int				median;
	int				len_stack;

	current = *stack;
	len_stack = size_stack(*stack);
	median = len_stack / 2;
	while (current)
	{
		if (current->index <= median)
			current->median = "up";
		else if (current->index > median)
			current->median = "down";
		current = current->next;
	}
}

void	verif_2_sign(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-') &&
				((argv[i][j + 1] == '\0') ||
				(argv[i][j + 1] == '+' || argv[i][j + 1] == '-')))
			{
				free_av(argv);
				return_error();
			}
			j++;
		}
		i++;
	}
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
