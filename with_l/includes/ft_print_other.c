/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:17 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:33:19 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_other(char c, t_list_flags flags)
{
	int	count;

	count = 1;
	if (flags.minus)
	{
		ft_putchar_fd(c, 1);
		if (flags.width)
			count += ft_add_width(' ', flags.width - 1);
	}
	else if (!flags.minus)
	{
		if (flags.width)
			count += ft_add_width(' ', flags.width - 1);
		ft_putchar_fd(c, 1);
	}
	return (count);
}
