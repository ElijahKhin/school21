/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/12 18:18:37 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *format, ...)
{
	int		runner;
	int		printed;
	va_list	arg_ptr;

	runner = 0;
	printed = 0;
	va_start(arg_ptr, format);
	ft_atoi(ft_substr(format, format[3], format[ ])
	while (format[runner] != '\0')
	{
		if (format[runner] == '%')
		{
/*			if (format[runner + 1] == '-')
			{
				print_width(ft_substr(
			}*/
			printed += print_arg(format[++runner], arg_ptr);
			runner++;
		}
		else
			printed += write(1, &format[runner++], 1);
	}
	return (printed);
}

