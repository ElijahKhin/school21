/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:11 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:33:12 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_width_int(t_list_flags flags, int size, int num)
{
	int	count;

	count = 0;
	if (flags.zero)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			count++;
		}
		count += ft_add_width('0', flags.width - size);
	}
	else if (flags.precise >= size)
	{
		if (num < 0)
			count += ft_add_width(' ', flags.width - flags.precise - 1);
		else
			count += ft_add_width(' ', flags.width - flags.precise);
	}
	else
		count += ft_add_width(' ', flags.width - size);
	return (count);
}

int	check_precision_int(t_list_flags flags, int size, int num)
{
	int	i;
	int	count;		

	i = 0;
	count = 0;
	if (num < 0 && flags.precise < size && !flags.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (flags.precise > 0)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			count++;
			i--;
		}
		while (i++ < flags.precise - size)
		{
			write(1, "0", 1);
			count++;
		}
	}
	return (count);
}

int	check_minus_int(t_list_flags flags, int size, char *str, int num)
{
	int	count;

	count = 0;
	if (num < 0)
		str++;
	if (flags.minus)
	{
		count += check_precision_int(flags, size, num);
		count += ft_putstr_fd(str, 1);
		count += check_width_int(flags, size, num);
	}
	else if (!flags.minus)
	{
		count += check_width_int(flags, size, num);
		count += check_precision_int(flags, size, num);
		count += ft_putstr_fd(str, 1);
	}
	return (count);
}

int	ft_print_int(t_list_flags flags, va_list args)
{
	int		num;
	char	*str;
	int		size;
	int		count;

	num = va_arg(args, int);
	str = ft_itoa(num);
	size = ft_strlen(str);
	count = 0;
	if (flags.zero && (flags.minus || flags.precise >= 0))
		flags.zero = 0;
	if (flags.precise == 0 && *str == '0')
	{
		count += ft_add_width(' ', flags.width);
		return (count);
	}
	count += check_minus_int(flags, size, str, num);
	free(str);
	return (count);
}
