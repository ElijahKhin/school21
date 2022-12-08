/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:55:18 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 20:28:40 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_space_plus(t_arginfo *info)
{
	int		twin;
	va_list	copy;

	va_copy(copy, info->arg_ptr);
	twin = va_arg(copy, int);
	if ((info -> spec == 'd' | info
			-> spec == 'i') && info -> space == 1 && twin >= 0)
		info -> printed += write(1, " ", 1);
	if ((info -> spec == 'd' | info
			-> spec == 'i') && info -> plus
		== 1 && twin >= 0)
		info -> printed += write(1, "+", 1);
}

void	arg_length(t_arginfo *info)
{
	va_list	copy;

	va_copy(copy, info->arg_ptr);
	if (info -> spec == 'c' || info -> spec == '%')
		info -> arg_len = 1;
	if (info -> spec == 's')
		info -> arg_len = ft_strlen(va_arg(copy, char *), info->precision);
	if (info -> spec == 'd' || info -> spec == 'i')
		info -> arg_len = num_len(va_arg(copy, int), 10, info);
	if (info -> spec == 'u')
		info -> arg_len = num_len(va_arg(copy, unsigned int), 10, info);
	if (info -> spec == 'p')
		info -> arg_len = num_len(va_arg(copy, unsigned long int),
				16, info) + 2;
	if (info -> spec == 'x' || info -> spec == 'X')
		info -> arg_len = num_len(va_arg(copy, unsigned int), 16, info);
	if (info->precision == 0 && info->zero == 0)
		info->arg_len = 0;
}

void	print_arg_one(t_arginfo *info)
{
	if (info->spec == 'c')
		info->printed += ft_print_char(va_arg(info->arg_ptr, int));
	if (info->spec == 's')
		info->printed += ft_print_str(va_arg(info->arg_ptr, char *),
				info->arg_len);
	if (info->spec == 'd' || info->spec == 'i')
		info->printed += ft_print_nbr(va_arg(info->arg_ptr, int), info);
	if (info->spec == 'u')
	{
		info->printed += precision_unbr(info);
		info->printed += ft_unsigned_nbr(va_arg(info->arg_ptr,
					unsigned int), info);
	}
}

void	print_arg_two(t_arginfo *info)
{
	if (info->spec == 'p')
	{
		info->printed += ox(info);
		info->printed += ft_print_hex(va_arg(info->arg_ptr, unsigned long int),
				info->spec, info);
	}
	if (info->spec == 'x' || info->spec == 'X')
	{
		info->printed += precision_unbr(info);
		info->printed += ox(info);
		info->printed += ft_print_hex(va_arg(info->arg_ptr, unsigned int),
				info->spec, info);
	}
	if (info->spec == '%')
		info->printed += write(1, &"%", 1);
}

void	check_print(t_arginfo *info)
{
	if (info->left_padding)
	{
		print_arg_one(info);
		print_arg_two(info);
		padding_one(info);
		padding_two(info);
	}
	else
	{
		padding_one(info);
		padding_two(info);
		print_arg_one(info);
		print_arg_two(info);
	}
}
