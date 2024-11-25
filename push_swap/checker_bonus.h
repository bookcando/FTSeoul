/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:38:45 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 14:59:12 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*up;
	struct s_stack	*down;
}	t_stack;

void	ml_exit(t_stack **stack_a, t_stack **stack_b);
int		check_redundancy(t_stack **stack);
int		check_sorted(t_stack **stack);
void	ml_integer_parser(t_stack **stack, int argc, const char **argv);
int		instruction_add(int inst);
char	*gnl_simple(t_stack **stack_a, t_stack **stack_b, int fd);
void	ml_inst_parser(t_stack **stack_a, t_stack **stack_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	stack_connect_elements(t_stack *upper, t_stack *lower);
void	stack_initial_connect(t_stack **stack);
void	stack_initial_add(t_stack **stack, int input);
void	stack_swap(t_stack **stack, char c);
void	stack_push(t_stack **from, t_stack **to, char f, char t);
void	stack_rotate(t_stack **stack, char c);
void	stack_rrotate(t_stack **stack, char c);
int		free_stacks(t_stack **a, t_stack **b);
#endif