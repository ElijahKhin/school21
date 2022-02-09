/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:32:55 by sworker           #+#    #+#             */
/*   Updated: 2022/02/09 15:44:43 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_char(t_list_flags flags, va_list args)
{
	if (flags.minus == 1 && flags.width > 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ft_add_width(' ', flags.width - 1);
		return (flags.width);
	}
	else if (flags.minus == 0 && flags.width > 1)
	{
		if (flags.zero)
			ft_add_width('0', flags.width - 1);
		else
			ft_add_width(' ', flags.width - 1);
	}
	ft_putchar_fd(va_arg(args, int), 1);
	if (flags.width > 1)
		return (flags.width);
	return (1);
}
