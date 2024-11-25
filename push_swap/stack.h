/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:49:43 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 15:45:56 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*up;
	struct s_stack	*down;
}	t_stack;

void	ml_integer_parser(t_stack **stack, int argc, const char **argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_strcpy_nonzero(char *src, char *dst);
int		trigen_right_bs(t_stack **from, t_stack **to, int count, int first);
int		right_init(t_stack **from, t_stack **to, int count);
int		trigen_reverse_sb(t_stack **from, t_stack **to, int count, int first);
int		smallest_first(t_stack **stack, int count);
int		reverse_init(t_stack **from, t_stack **to, int count);
int		instruction_add(int cur_inst);
int		right_m(t_stack **from, t_stack **to, char f, char t);
int		reverse_m(t_stack **from, t_stack **to, char f, char t);
int		send_reversed_right(t_stack **from, t_stack **to, char f, char t);
int		send_right_reversed(t_stack **from, t_stack **to, char f, char t);
int		smallest_first(t_stack **stack, int count);
int		smallest_middle(t_stack **from, t_stack **to, int count);
int		three_smallest_first(t_stack **stack);
int		reverse_init(t_stack **from, t_stack **to, int count);
int		biggest_first(t_stack **stack, int count);
int		biggest_middle(t_stack **from, t_stack **to, int count);
int		three_biggest_first(t_stack **stack);
int		right_init(t_stack **from, t_stack **to, int count);
int		small_sort(t_stack **from, t_stack **to, int count);
void	stack_connect_elements(t_stack *upper, t_stack *lower);
void	stack_initial_connect(t_stack **stack);
void	stack_initial_add(t_stack **stack, int input);
void	stack_swap(t_stack **stack, char c);
void	stack_push(t_stack **from, t_stack **to, char f, char t);
void	stack_rotate(t_stack **stack, char c);
void	stack_rrotate(t_stack **stack, char c);
char	*get_stage_string(t_stack **stack, int elements, int stages);
int		stage_first(t_stack **from, t_stack **to, int elements, char *string);
int		stage_even(t_stack **to, t_stack **from, int index, char *string);
int		stage_odd(t_stack **from, t_stack **to, int index, char *string);
int		stage_last(t_stack **to, t_stack **from, int index, char *string);
char	*mirror(char *string);
char	*mirror_break(char *string);
int		pass_again(int input);
void	ml_for(void (*func)(t_stack **, char), t_stack **stack, char c, int t);
int		stack_value_compare(t_stack *a, t_stack *b, int ia, int ib);
int		free_stacks(t_stack **a, t_stack **b);
int		action_by_index(t_stack **from, t_stack **to, int count, int index);
t_stack	*stack_go(t_stack **stack, int count);
int		count_to_index(int count);
void	ml_integer_parser(t_stack **stack, int argc, const char **argv);
void	ml_exit(t_stack **stack_a, t_stack **stack_b);
int		check_redundancy(t_stack **stack);
int		check_sorted(t_stack **stack);
int		stack_count(t_stack **stack);
#endif