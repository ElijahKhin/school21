/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:28:13 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:28:13 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printing(long int nb, int fd)
{
	if (nb > 0)
	{
		printing(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	if (fd < 0)
		return ;
	nb = n;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = -nb;
		}
		printing(nb, fd);
	}
}
