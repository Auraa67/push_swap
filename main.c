/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:47:49 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/31 15:00:36 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	init_a_b(t_stack_node **a, t_stack_node **b, int argc)
{
	(*a) = NULL;
	(*b) = NULL;
	if (argc == 1)
	{
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*args;
	char			**tokens;

	init_a_b(&a, &b, argc);
	if (argv[1][0] != '\0')
	{
		args = join_args(argc, argv);
		tokens = ft_split(args, ' ');
		verif_2_sign(argv);
		stuck_or_not(tokens);
		init_stack(&a, tokens);
		if (ft_strcmp(contain_clone(a), "no") == 0
			&& ft_strcmp(is_sorted(a), "no") == 0)
		{
			push_swap(a, b, get_min(a, size_stack(a), "value"));
		}
		else
			ft_stackclear(&a);
	}
	else
		return_error();
	return (0);
}
