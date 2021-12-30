/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:11:07 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/26 16:11:07 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf_char(char	a)
{
	write(1, &a, 1);
}

int	ft_putstr(char	*str)
{
	int	i;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_strlen(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	check_flag(const char	*format, int	i, void *param)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
	{
		ft_printf_char((int)param);
		count++;
	}
	if (format[i] == 's')
		count += ft_putstr((char *)param);
	if (format[i] == 'p')
	{
		write(1, "0x", 2);
		count += ft_printf_pointer((unsigned long long)param);
	}
	if (format[i] == 'd' || format[i] == 'i')
		count += ft_putnbr((int)param);
	if (format[i] == 'u')
		count += ft_putnbr_U((unsigned int)param);
	if (format[i] == 'x' || format[i] == 'X')
		count += ft_printf_hex((unsigned int)param, format[i]);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	argptr;
	int		count;

	i = 0;
	count = 0;
	va_start (argptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				count += write(1, &format[i], 1);
			else
				count += check_flag(format, i + 1, va_arg(argptr, void *));
			i += 2;
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	va_end (argptr);
	return (count);
}
