/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:37:04 by fhiedi            #+#    #+#             */
/*   Updated: 2022/01/17 21:30:23 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	char		p;
	static int	count;

	count = 0;
	if (nb >= 10)
		ft_putnbr_u(nb / 10);
	p = (nb % 10) + '0';
	write(1, &p, 1);
	count++;
	return (count);
}

int	ft_putnbr(int nb)
{
	static int	count;

	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		count += ft_putnbr_u(-nb);
		count++;
	}
	else
		count += ft_putnbr_u(nb);
	return (count);
}
