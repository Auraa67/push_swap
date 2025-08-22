/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:37:26 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 17:59:27 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int						index;
	int						value;
	int						cost;
	char					*median;
	char					*min_cost;
	struct s_stack_node		*target_node;
	struct s_stack_node		*prev;
	struct s_stack_node		*next;
}					t_stack_node;

void			rotate_a(t_stack_node **stack_a, char *return_type);
void			rotate_b(t_stack_node **stack_a, char *return_type);
void			rotate_r(t_stack_node **stack_a, t_stack_node **stack_b,
					char *return_type);
void			swap(t_stack_node **stack);
void			swap_a(t_stack_node **stack_a, char *return_type);
void			swap_b(t_stack_node **stack_a, char *return_type);
void			swap_ss(t_stack_node **stack_a, t_stack_node **stack_b,
					char *return_type);
void			reverse_rotate_a(t_stack_node **stack_a, char *return_type);
void			reverse_rotate_b(t_stack_node **stack_b, char *return_type);
void			reverse_rotate_r(t_stack_node **stack_a, t_stack_node **stack_b,
					char *return_type);
void			push_a(t_stack_node **a, t_stack_node **b, char *return_type);
void			push_b(t_stack_node **a, t_stack_node **b, char *return_type);

void			push_swap(t_stack_node *stack_a, t_stack_node *stack_b,
					int min_a);
void			sort_min(t_stack_node **a);
void			sort_three(t_stack_node **a);
void			sort_four(t_stack_node **a, t_stack_node **b);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			first_step(t_stack_node **a, t_stack_node **b);
void			second_step(t_stack_node **a, t_stack_node **b);
void			ft_stackclear(t_stack_node **stack);

void			init_stack(t_stack_node **stack, char *argv[]);
void			back_up_top(t_stack_node **stack_a, int min_a);
void			free_argv(char **argv, t_stack_node **stack, int i, int last);
char			**ft_split(char *s, char c);
char			*ft_new_strdup(char *s);
void			return_error(void);
void			verif_2_sign(char **argv);
void			free_av(char **av);
char			*is_sorted(t_stack_node *stack);
char			*contain_clone(t_stack_node *stack);
void			stuck_or_not(char **tokens);
void			check_void(char *str, char *joined);
int				size_stack(t_stack_node *stack);
char			*join_args(int argc, char **argv);
int				get_max(t_stack_node *stack, int size, char *return_type);
int				get_min(t_stack_node *stack, int size, char *return_type);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_new_strlen(char *str);
int				return_index(t_stack_node *stack, int target);
void			simple_exec(t_stack_node **stack_a, t_stack_node **stack_b,
					char *operation);
void			multiple_exec(t_stack_node **stack_a, t_stack_node **stack_b,
					int repetition, char *operation);
void			init_index(t_stack_node **stack);
void			init_median(t_stack_node **stack);
void			cost_calculus(t_stack_node **stack_a, t_stack_node *stack_b);
void			is_cheapest(t_stack_node **stack_a);
void			raise_target(t_stack_node **stack, t_stack_node *cheap,
					char *name);
void			find_target_of_a(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			find_target_of_b(t_stack_node **stack_b,
					t_stack_node **stack_a);
t_stack_node	*retrieve_target_b(t_stack_node *stack_b,
					t_stack_node *stack_a);
t_stack_node	*last_first_node(t_stack_node *stack, char *return_type);
t_stack_node	*retrieve_cheap(t_stack_node *stack_a);

#endif
