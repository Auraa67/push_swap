/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:06:30 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/31 14:54:09 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*contain_clone(t_stack_node *stack)
{
	t_stack_node	*i;
	t_stack_node	*j;

	if (!stack)
		return (0);
	i = stack;
	while (i)
	{
		j = stack;
		while (j->next != NULL)
		{
			if (i->value == j->next->value
				&& i->index != j->next->index)
			{
				ft_stackclear(&stack);
				return_error();
			}
			j = j->next;
		}
		i = i->next;
	}
	return ("no");
}

char	*is_sorted(t_stack_node *stack)
{
	t_stack_node	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return ("no");
		temp = temp->next;
	}
	return ("yes");
}

void	check_void(char *str, char *joined)
{
	int		j;
	int		len;

	j = 0;
	len = 0;
	while (str[j])
	{
		while (str[j] == ' ' && str[j])
		{
			j++;
			len++;
		}
		if (str[j] != '\0')
		{
			j++;
		}
	}
	if (len == ft_new_strlen(str))
	{
		free(joined);
		return_error();
	}
}

void	free_argv(char **argv, t_stack_node **stack, int i, int last)
{
	if (i == last)
		free(argv[i]);
	else
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
	}
	if (i >= 0)
	{
		free(argv);
		ft_stackclear(stack);
	}
	return_error();
}

void	stuck_or_not(char **tokens)
{
	int	i;
	int	j;
	int	contain_sign;

	i = 0;
	while (tokens[i])
	{
		contain_sign = 0;
		j = 0;
		while (tokens[i][j])
		{
			if (tokens[i][j] == '+' || tokens[i][j] == '-')
			{
				contain_sign++;
			}
			if (tokens[i][j + 1] == '\0' && contain_sign > 1)
			{
				free_av(tokens);
				return_error();
			}
			j++;
		}
		i++;
	}
}
