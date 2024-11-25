/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrap_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:14:31 by minsulee          #+#    #+#             */
/*   Updated: 2022/12/21 14:34:44 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ml_malloc(size_t size)
{
	void	*ret_ptr;

	ret_ptr = malloc(size);
	if (ret_ptr == 0)
	{
		perror("error on function *malloc*");
		return (0);
	}
	return (ret_ptr);
}

ssize_t	ml_write(int fildes, const void *buf, size_t nbyte)
{
	ssize_t	ret;

	ret = write(fildes, buf, nbyte);
	if (ret < 0)
		perror("error on function *write*");
	return (ret);
}

int	ml_close(int fildes)
{
	int	ret;

	ret = close(fildes);
	if (ret == -1)
		perror("error on function *close*");
	return (ret);
}

ssize_t	ml_read(int fildes, void *buf, size_t nbyte)
{
	ssize_t	ret;

	ret = read(fildes, buf, nbyte);
	if (fildes < 0)
		perror("error on fd(fd is less than zero). *read*");
	else if (ret < 0)
		perror("error on function *read*");
	return (ret);
}
