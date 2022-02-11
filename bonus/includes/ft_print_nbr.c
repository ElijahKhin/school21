/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:09:13 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/11 14:11:08 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int ft_unsigned_nbr(unsigned int nbr)
{
	static int runner;

	runner = 0;
	if (nbr / 10)
		ft_unsigned_nbr(nbr / 10);
	nbr = nbr % 10 + 48;
	runner += write(1, &nbr, 1);
	return (runner);
}

int ft_print_nbr(int nbr)
{
	int printed;

	printed = 0;
	if (nbr < 0)
	{
		printed = write(1, "-", 1);
		printed += ft_unsigned_nbr(-nbr);
	}
	else
		printed += ft_unsigned_nbr(nbr);
   	return (printed);
}
