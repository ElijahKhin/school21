/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:35 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:33:37 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_minus_ptr(t_list_flags flags, int size, char *str)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_putstr_fd(str, 1);
		count += ft_add_width(' ', flags.width - (size + 2));
	}
	else if (!flags.minus)
	{
		count += ft_add_width(' ', flags.width - (size + 2));
		count += ft_putstr_fd("0x", 1);
		count += ft_putstr_fd(str, 1);
	}
	return (count);
}

int	ft_print_ptr(t_list_flags flags, va_list args)
{
	char				*str;
	int					size;
	int					count;
	unsigned long long	num;

	num = va_arg(args, unsigned long long);
	if (!num)
	{
		if (flags.precise == 0)
			str = ft_strdup("");
		else
			str = ft_strdup("0");
	}
	else
		str = ft_convert_pointer("0123456789abcdef", num);
	size = ft_strlen(str);
	count = 0;
	count += check_minus_ptr(flags, size, str);
	free(str);
	return (count);
}
