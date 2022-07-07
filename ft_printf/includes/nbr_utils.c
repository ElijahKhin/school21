/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:20:54 by fhiedi            #+#    #+#             */
/*   Updated: 2022/04/11 20:30:34 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int	precision_unbr(t_arginfo *info)
{
	int	printed;
	int	minus;

	minus = 0;
	printed = 0;
	while (info->precision != 2147483647 && info
		->precision - info->arg_len - minus > 0)
	{
		minus++;
		printed += write(1, "0", 1);
	}
	return (printed);
}

int	num_len(long long n, int base, t_arginfo *info)
{
	int	size;

	info->minus = 0;
	info->zero = n;
	if ((unsigned long int)n >= 9223372036854775807 && base == 16)
		return (20);
	size = 1;
	if (n < 0 && base == 10)
	{
		if (info->zero_padding == 1)
			info -> printed += write(1, "-", 1);
		info->minus = 1;
		size++;
		n *= -1;
	}
	while (n >= base)
	{
		n /= base;
		size++;
	}
	return (size);
}

int	ft_unsigned_nbr(unsigned int nbr, t_arginfo *info)
{
	static int	runner;

	runner = 0;
	if (!(info->precision == 0 && nbr == 0))
	{
		if (nbr / 10)
			ft_unsigned_nbr(nbr / 10, info);
		nbr = nbr % 10 + 48;
		runner += write(1, &nbr, 1);
	}
	return (runner);
}

int	ft_print_nbr(int nbr, t_arginfo *info)
{
	int	printed;
	int	prec_twin;

	printed = 0;
	if (!(info->precision == 0 && nbr == 0))
	{
		if ((info->precision != -1 || info->zero_padding != 1) && nbr < 0)
		{
			printed += write(1, "-", 1);
			info->arg_len -= 1;
		}
		prec_twin = info->precision;
		while (prec_twin - info->arg_len > 0)
		{
			printed += write(1, "0", 1);
			prec_twin--;
		}
		if (nbr < 0)
			printed += ft_unsigned_nbr(-nbr, info);
		else
			printed += ft_unsigned_nbr(nbr, info);
	}
	return (printed);
}
