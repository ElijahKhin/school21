/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:29:21 by sworker           #+#    #+#             */
/*   Updated: 2022/02/09 15:32:29 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list_flags	default_flags(void)
{
	t_list_flags	flags;	

	flags.dot = 0;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.precise = -1;
	return (flags);
}

int	is_flag(char c)
{
	if (c == '-')
		return (1);
	else if (c == '*')
		return (1);
	else if (c == '.')
		return (1);
	else if (ft_isdigit(c))
		return (1);
	else
		return (0);
}

static t_list_flags	parse_star(t_list_flags flags, va_list args)
{
	if (flags.dot == 1)
		flags.precise = va_arg(args, int);
	else if (flags.width < 1)
	{
		flags.width = va_arg(args, int);
		if (flags.width < 0)
		{
			flags.width *= (-1);
			flags.minus = 1;
		}
	}
	return (flags);
}

t_list_flags	parser(t_list_flags flags, const char *str, va_list args)
{
	int	i;

	i = 0;
	while (str[i] && is_flag(str[i]))
	{
		if (str[i] == '-')
			flags.minus = 1;
		else if (str[i] == '0' && flags.width < 1 && flags.dot == 0)
			flags.zero = 1;
		else if (ft_isdigit(str[i]) && flags.dot == 0)
			flags.width = (flags.width * 10) + (str[i] - 48);
		else if (str[i] == '.')
		{
			flags.dot = 1;
			flags.precise = 0;
		}
		else if (ft_isdigit(str[i]) && flags.dot == 1)
			flags.precise = (flags.precise * 10) + (str[i] - 48);
		else if (str[i] == '*')
			flags = parse_star(flags, args);
		i++;
	}
	return (flags);
}

int	ft_printf(const char *str, ...)
{
	int				i;
	va_list			args;
	t_list_flags	flags;
	int				syms;

	i = 0;
	syms = 0;
	va_start(args, str);
	flags = default_flags();
	syms = main_loop(str, flags, args);
	va_end(args);
	return (syms);
}
