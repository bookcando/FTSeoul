/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:20:14 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 19:04:14 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flag
{
	unsigned char	sharp;
	unsigned char	plus;
	unsigned char	space;
	unsigned char	minus;
	unsigned char	zero;
	ssize_t			width;
	unsigned char	dot;
	ssize_t			precision;
	unsigned char	format;
}				t_flag;

int		ft_printf(const char *input, ...);
int		case_all(const char **input, va_list *arg);
int		read_print(const char **input, va_list *arg, int *count);
int		flag_get(const char **string, t_flag *list);
int		is_flag(const char **string, t_flag *list);
int		pos_atoi(const char **string);
int		flag_check(t_flag *list);
void	flag_init(t_flag *list);
int		put_sign(t_flag *list, char sign);
int		width_filler(size_t numlen, t_flag *list);
int		write_c(size_t length, unsigned char c);
size_t	case_p(void *ptr, t_flag *list);
size_t	case_pct(t_flag *list);
int		case_c(int c, t_flag *list);
size_t	case_s(unsigned char *c, t_flag *list);
int		print_str(unsigned char *c, size_t length);
int		get_strlen(unsigned char *c);
ssize_t	case_di(int num, t_flag *list);
ssize_t	case_x(size_t num, t_flag *list);
ssize_t	case_u(size_t num, t_flag *list);
size_t	get_numlen_numpart_s(ssize_t num, int base);
size_t	get_numlen_numpart_u(size_t num, int base);
size_t	max(size_t a, size_t b);
size_t	min(size_t a, size_t b);
int		print_num_s(char sign, ssize_t num, int base_num, char *base_str);
int		print_num_u(size_t num, int base_num, char *base_str);
int		sign_detector(ssize_t num, t_flag *list);
int		numlen_initializer(ssize_t num, t_flag *list);
int		get_numlen(ssize_t num, t_flag *list, size_t *numlen, size_t *pzero);
size_t	rule_px(unsigned int num, t_flag *list, size_t numlen);
int		write_num_pre(size_t numlen, size_t pzero, t_flag *list, char sign);
#endif