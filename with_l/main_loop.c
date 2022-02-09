/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:53:08 by sworker           #+#    #+#             */
/*   Updated: 2022/02/08 16:40:52 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	main_loop(const char	*str, t_list_flags flags, va_list args)
{
	int	syms;
	int	i;

	i = 0;
	syms = 0;
	while (str[i])
	{
		if (str[i] != '%')
			syms++;
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			flags = default_flags();
			flags = parser(flags, &str[++i], args);
			while (is_flag(str[i]))
				i++;
			syms += ft_print_arg(flags, str[i], args);
		}
		else
			ft_putchar_fd(str[i], 1);
		if (str[i] != '\0')
			i++;
	}
	return (syms);
}
