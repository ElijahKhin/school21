/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:25 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:33:27 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_percent(t_list_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		ft_putchar_fd('%', 1);
		count += ft_add_width(' ', flags.width - 1);
	}
	else if (!flags.minus)
	{
		if (flags.zero)
			count += ft_add_width('0', flags.width - 1);
		else
			count += ft_add_width(' ', flags.width - 1);
		ft_putchar_fd('%', 1);
	}
	return (count + 1);
}
