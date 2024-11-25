/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrap_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:53:44 by minsulee          #+#    #+#             */
/*   Updated: 2022/12/21 14:30:56 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ml_pipe(int fildes[2])
{
	int	ret;

	ret = pipe(fildes);
	if (ret < 0)
		perror("error on function *pipe*");
	return (ret);
}

int	ml_dup2(int fildes, int fildes2)
{
	int	ret;

	ret = dup2(fildes, fildes2);
	if (ret == -1)
		perror("error on function *dup2*");
	return (ret);
}
