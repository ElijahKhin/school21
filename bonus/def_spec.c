/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:57:29 by fhiedi            #+#    #+#             */
/*   Updated: 2022/03/09 16:39:47 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int def_spec(char ch, va_list arg_ptr)
{
	int printed;

	printed = 0;
	if (ch == 'c')
		printed += ft_print_char(va_arg(arg_ptr, int));
	if (ch == 's')
		printed += ft_print_str(va_arg(arg_ptr, char *));
	if (ch == 'd' || ch == 'i')
		printed += ft_print_nbr(va_arg(arg_ptr, int));
	if (ch == 'u')
		printed += ft_unsigned_nbr(va_arg(arg_ptr, unsigned int));
	if (ch == 'p')
		printed += ft_print_hex(va_arg(arg_ptr, unsigned long int), ch);
	if (ch == 'x' || ch == 'X')
		printed += ft_print_hex(va_arg(arg_ptr, unsigned int), ch);
	if (ch == '%')
		printed += write(1, &"%", 1);

	return (printed);
}
