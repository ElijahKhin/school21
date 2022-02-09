/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:50 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:33:51 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_add_unsig_width(int size, t_list_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero && !flags.minus && flags.precise < 0)
		count += ft_add_width('0', flags.width - size);
	else if (flags.precise >= size)
		count += ft_add_width(' ', flags.width - flags.precise);
	else
		count += ft_add_width(' ', flags.width - size);
	return (count);
}

int	print_unsig_precision(int size, t_list_flags flags)
{
	int	i;

	if (flags.precise)
	{
		i = -1;
		while (++i < flags.precise - size)
			ft_putchar_fd('0', 1);
		return (i);
	}
	return (0);
}

int	check_minus_unsig(char *str, int size, t_list_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += print_unsig_precision(size, flags);
		ft_putstr_fd(str, 1);
		count += size;
		count += check_add_unsig_width(size, flags);
	}
	else if (!flags.minus)
	{
		count += check_add_unsig_width(size, flags);
		count += print_unsig_precision(size, flags);
		ft_putstr_fd(str, 1);
		count += size;
	}
	return (count);
}

int	ft_print_unsigned_int(t_list_flags flags, va_list args)
{
	char	*str;
	int		size;
	int		count;

	str = ft_utoa(va_arg(args, unsigned int));
	size = ft_strlen(str);
	count = 0;
	if (flags.precise == 0 && str[0] == '0')
	{
		count += ft_add_width(' ', flags.width);
		return (count);
	}
	count += check_minus_unsig(str, size, flags);
	free(str);
	return (count);
}
