/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/03/09 16:54:30 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *format, ...)
{
	t_arginfo	arginfo;
	char 		*take;
	int			runner;
	int			printed;
	va_list		arg_ptr;

	arginfo.width = 0;
	arginfo.printed = 0;
	runner = 0;
	printed = 0;
	va_start(arg_ptr, format);
	while (format[runner] != '\0')
	{
		if (format[runner] == '%')
		{	
			take = ft_substr(format, ++runner, ft_strlen(format) + 1);
			check_flags(take, &arginfo);
			free(take);
			take = NULL;
			if (arginfo.width != 1)
				runner += num_len(arginfo.width) + 1;
			else
				runner++;
			printed += def_spec(format[runner], arg_ptr);
			arginfo.width = arginfo.width - 2;
			while (arginfo.width-- > 0)
				printed += write(1, " ", 1);
			runner++;
		}
		else
		{
			printed += write(1, &format[runner++], 1);
		}
	}
	return (printed);
}

