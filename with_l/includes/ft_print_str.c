/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:43 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:33:44 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_precesion_str(char *str, int size, t_list_flags flags)
{
	int	i;

	i = 0;
	if (flags.precise >= 0 && flags.precise >= size)
		while (str[i])
			ft_putchar_fd(str[i++], 1);
	else if (flags.precise >= 0 && flags.precise < size)
		while (i < flags.precise)
			ft_putchar_fd(str[i++], 1);
	else
		while (str[i])
			ft_putchar_fd(str[i++], 1);
	return (i);
}

int	check_prec(char *str, int size, t_list_flags flags)
{
	int	i;

	i = 0;
	if (flags.precise >= 0 && flags.precise >= size)
		while (str[i])
			i++;
	else if (flags.precise >= 0 && flags.precise < size)
		while (i < flags.precise)
			i++;
	else
		while (str[i])
			i++;
	return (i);
}

int	check_minus_str(char *str, int size, t_list_flags flags)
{
	int	count;
	int	res_prec;

	count = 0;
	res_prec = check_prec(str, size, flags);
	if (!flags.minus && flags.width > res_prec)
	{
		if (flags.zero)
			count += ft_add_width('0', flags.width - res_prec);
		else
			count += ft_add_width(' ', flags.width - res_prec);
		count += check_precesion_str(str, size, flags);
	}
	else if (flags.minus && flags.width > res_prec)
	{
		count += check_precesion_str(str, size, flags);
		count += ft_add_width(' ', flags.width - res_prec);
	}
	else
		count += check_precesion_str(str, size, flags);
	return (count);
}

int	ft_print_str(t_list_flags flags, va_list args)
{
	char	*str;
	int		size;
	int		count;
	int		is_null;

	count = 0;
	is_null = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
		is_null = 1;
	}
	size = ft_strlen(str);
	count += check_minus_str(str, size, flags);
	if (is_null)
		free(str);
	return (count);
}
