/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/14 19:14:04 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *format, ...)
{
	int *data_spec;
	char *take;
	int		runner;
	int		printed;
	va_list	arg_ptr;

	runner = 0;
	printed = 0;
	va_start(arg_ptr, format);
	
	while (format[runner] != '\0')
	{
//		printf("The first print!: %c\n", format[runner]);
		if (format[runner] == '%')
		{	
			take = ft_substr(format, runner + 1, ft_strlen(format) + 1);
			data_spec = check_flags(take);
			printed += data_spec[0];
			free(take);
			take = NULL;
			printed += print_arg(format[runner + data_spec[1]], arg_ptr);
			runner++;
		}
		else
			printed += write(1, &format[runner++], 1);
	}
	return (printed);
}

