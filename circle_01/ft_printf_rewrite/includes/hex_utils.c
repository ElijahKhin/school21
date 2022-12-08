/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:17:08 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 20:29:44 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ox(t_arginfo *info)
{
	int		printed;
	va_list	copy;

	va_copy(copy, info->arg_ptr);
	printed = 0;
	if (!(info->precision == 0 && info->zero == 0))
	{
		if (info->spec == 'p')
			printed += write(1, "0x", 2);
		if ((info->spec == 'x' || info->spec == 'X') && info
			->sharp && va_arg(copy, unsigned int) != 0)
		{
			printed += write(1, "0", 1);
			printed += write(1, &info->spec, 1);
		}
	}
	return (printed);
}

int	recursion_hex(unsigned long int arg, char ch, t_arginfo *info)
{
	static int	printed;
	char		*hex;
	char		printed_ch;

	hex = "0123456789abcdef";
	printed = 0;
	if (!(info->precision == 0 && info->zero == 0))
	{
		if (arg / 16)
			printed = recursion_hex(arg / 16, ch, info);
		if (ch >= 65 && ch <= 90)
			printed_ch = ft_toupper(hex[arg % 16]);
		else
			printed_ch = hex[arg % 16];
		printed += write(1, &printed_ch, 1);
	}
	return (printed);
}

int	ft_print_hex(unsigned long int arg, char ch, t_arginfo *info)
{
	int		printed;

	printed = 0;
	printed += recursion_hex(arg, ch, info);
	return (printed);
}
