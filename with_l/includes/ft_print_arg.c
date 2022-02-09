/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:32:49 by sworker           #+#    #+#             */
/*   Updated: 2022/02/09 16:38:35 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_arg(t_list_flags flags, char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(flags, args);
	else if (c == 's')
		count = ft_print_str(flags, args);
	else if (c == 'p')
		count = ft_print_ptr(flags, args);
	else if (c == 'd' || c == 'i')
		count = ft_print_int(flags, args);
	else if (c == 'u')
		count = ft_print_unsigned_int(flags, args);
	else if (c == 'x')
		count = ft_print_hex("0123456789abcdef", flags, args);
	else if (c == 'X')
		count = ft_print_hex("0123456789ABCDEF", flags, args);
	else if (c == '%')
		count = ft_print_percent(flags);
	else
		count = ft_print_other(c, flags);
	return (count);
}
