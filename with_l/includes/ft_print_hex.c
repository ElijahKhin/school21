/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:02 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:33:03 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_hex_precision(t_list_flags flags, int size)
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

int	print_hex_width(t_list_flags flags, int size)
{
	int	count;

	count = 0;
	if (flags.zero && !flags.minus && flags.precise < 0)
		count = ft_add_width('0', flags.width - size);
	else if (flags.precise >= size)
		count = ft_add_width(' ', flags.width - flags.precise);
	else
		count = ft_add_width(' ', flags.width - size);
	return (count);
}

int	check_minus_hex(t_list_flags flags, int size, char *str)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += check_hex_precision(flags, size);
		ft_putstr_fd(str, 1);
		count += size;
		count += print_hex_width(flags, size);
	}
	else if (!flags.minus)
	{
		count += print_hex_width(flags, size);
		count += check_hex_precision(flags, size);
		ft_putstr_fd(str, 1);
		count += size;
	}
	return (count);
}

int	ft_print_hex(char *hcase, t_list_flags flags, va_list args)
{
	char			*str;
	int				size;
	int				count;
	unsigned int	num;

	count = 0;
	num = va_arg(args, unsigned int);
	if (!num)
		str = ft_strdup("0");
	else
		str = ft_convert_pointer(hcase, num);
	size = ft_strlen(str);
	if (flags.precise == 0 && str[0] == '0')
	{
		count += ft_add_width(' ', flags.width);
		return (count);
	}
	count += check_minus_hex(flags, size, str);
	free(str);
	return (count);
}
