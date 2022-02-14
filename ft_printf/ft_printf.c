/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:19:40 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/11 14:55:19 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_hex_adr(unsigned long long dec_adr, char *hex_adr, int runner)
{
	char	*hex_base;
	int		runner2;

	hex_base = "0123456789abcdef";
	runner2 = runner;
	if (dec_adr > 0)
		create_hex_adr(dec_adr / 16, hex_adr, --runner2);
	hex_adr[runner] = hex_base[dec_adr % 16];
}

int	ft_print_pointer(unsigned long long dec_adr)
{
	int		runner;
	int		printed_chars;
	char	hex_adr[16];

	if (dec_adr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	printed_chars = 2;
	runner = 0;
	while (runner < 16)
		hex_adr[runner++] = '0';
	runner = 15;
	create_hex_adr(dec_adr, hex_adr, runner);
	runner = 0;
	while (hex_adr[runner] == '0')
		runner++;
	while (runner < 16)
	{
		write (1, &hex_adr[runner++], 1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	def_spf(char c, void *args)
{
	int	printed_chars;

	printed_chars = 0;
	if (c == 'c')
		printed_chars += ft_putchar((char)args);
	if (c == 's')
		printed_chars += ft_putstr((char *)args);
	if (c == 'p')
		printed_chars += ft_print_pointer((unsigned long long)args);
	if (c == 'd' || c == 'i')
		printed_chars += ft_putnbr((int)args);
	if (c == 'u')
		printed_chars += ft_putnbr_u((unsigned int)args);
	if (c == 'x' || c == 'X')
		printed_chars += ft_printf_hex((unsigned int)args, c);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	int		runner;
	int		printed_chars;
	va_list	arg_ptr;

	runner = 0;
	printed_chars = 0;
	va_start(arg_ptr, format);
	while (format[runner])
	{
		if (format[runner] == '%')
		{
			if (format[++runner] == '%')
				printed_chars += write(1, "%", 1);
			else
				printed_chars += def_spf(format[runner],
						va_arg(arg_ptr, void *));
			++runner;
		}
		else
			printed_chars += write(1, &format[runner++], 1);
	}
	va_end(arg_ptr);
	return (printed_chars);
}
