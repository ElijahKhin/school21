/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:01:04 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 14:25:42 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_write_number(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		recursive_write_number(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == MIN_INT)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	recursive_write_number(n, fd);
}
