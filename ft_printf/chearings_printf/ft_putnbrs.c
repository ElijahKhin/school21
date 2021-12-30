/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:25:11 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/26 17:25:16 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_U(unsigned int	nb)
{
	char		p;
	static int	count;

	count = 0;
	if (nb >= 10)
		ft_putnbr_U(nb / 10);
	p = (nb % 10) + '0';
	write(1, &p, 1);
	count++;
	return (count);
}

int	ft_putnbr(int	nb)
{
	static int	count;

	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		count += ft_putnbr_U(-nb);
		count++;
	}
	else
		count += ft_putnbr_U(nb);
	return (count);
}
