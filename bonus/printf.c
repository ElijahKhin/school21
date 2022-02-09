/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/09 14:59:52 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int parser(char ch, va_list arg_ptr)
{
	void *ret;
	int printed;

	ret = va_arg(arg_ptr, void *);
	printed = 0;
	if (ch == 'c')
		printed += write(1, &ret, 1);
	return (++printed);
}

int ft_printf(const char *format, ...)
{
	int		runner;
	int		printed;
	va_list	arg_ptr;

	runner = 0;
	printed = 0;
	va_start(arg_ptr, format);
	while (format[runner] != '\0')
	{
		if (format[runner] == '%')
			printed += parser(format[++runner], arg_ptr);
		else
			printed += write(1, &format[runner++], 1);
	}
	return(0);
}

int main(void)
{
	ft_printf("Hello %c", 'J');
	return (0);
}
