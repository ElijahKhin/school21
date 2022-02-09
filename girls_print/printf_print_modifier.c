/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_modifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfelwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:46:52 by tfelwood          #+#    #+#             */
/*   Updated: 2021/12/22 14:46:55 by tfelwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rec_putnbr(unsigned long long n, char base, const char *alph)
{
	char	s;

	if (n / base)
		ft_rec_putnbr (n / base, base, alph);
	if (alph)
		s = alph[n % base];
	else
		s = '0' + n % 10;
	write(1, &s, 1);
}

static void	ft_putnbr_hex(unsigned long long num, char format)
{
	const char				lowercase[] = "0123456789abcdef";
	const char				uppercase[] = "0123456789ABCDEF";

	if (format == 'X')
		ft_rec_putnbr(num, 16, uppercase);
	else
		ft_rec_putnbr(num, 16, lowercase);
}

static void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

static void	ft_putstr(const char *str, int size)
{
	if (str)
	{
		while (*str && size--)
			write(1, str++, 1);
	}
	else
	{
		if (size < 6)
			write(1, "(null)", size);
		else
			write(1, "(null)", 6);
	}
}

void	ft_print_modifier(t_print_info *info)
{
	int	num;

	if (*info->format == 's')
		ft_putstr(va_arg(info->args, char *), info->prec);
	else if (*info->format == 'i' || *info->format == 'd')
	{
		num = va_arg(info->args, int);
		if (num < 0)
			ft_rec_putnbr(-(long long)(num), 10, ((void *)0));
		else
			ft_rec_putnbr(num, 10, ((void *)0));
	}
	else if (*info->format == 'u')
		ft_rec_putnbr(va_arg(info->args, unsigned int), 10, ((void *)0));
	else if (*info->format == 'x')
		ft_putnbr_hex(va_arg(info->args, unsigned int), 'x');
	else if (*info->format == 'X')
		ft_putnbr_hex(va_arg(info->args, unsigned int), 'X');
	else if (*info->format == 'p')
		ft_putnbr_hex((unsigned long long) va_arg(info->args, void *), 'x');
	else if (*info->format == 'c')
		ft_putchar(va_arg(info->args, int));
	else
		ft_putchar(*info->format);
}
