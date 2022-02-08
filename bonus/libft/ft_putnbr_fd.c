/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:50:10 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/18 17:03:43 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	exc(int n)
{
	if (n == -2147483648)
		return (1);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 0;
	if (exc(n))
	{
		n /= 10;
		sign = 1;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
	if (sign)
		ft_putchar_fd('8', fd);
}
