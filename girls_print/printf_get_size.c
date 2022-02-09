/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfelwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:47:50 by tfelwood          #+#    #+#             */
/*   Updated: 2022/02/07 20:56:40 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	if (s)
	{
		while (s[size])
			++size;
	}
	else
		size = 6;
	return (size);
}

static int	ft_numberlen(unsigned long long n, char base)
{
	int	count;

	count = 1;
	while (n / base)
	{
		n /= base;
		++count;
	}
	return (count);
}

int	ft_get_size(t_print_info *info)
{
	int		num;
	int		size;
	va_list	copy;

	size = 1;
	va_copy(copy, info->args);
	if (*info->format == 's')
		size = (ft_strlen(va_arg(copy, char *)));
	else if (*info->format == 'u')
		size = (ft_numberlen(va_arg(copy, unsigned int), 10));
	else if (*info->format == 'x' || *info->format == 'X')
		size = (ft_numberlen(va_arg (copy, unsigned int), 16));
	else if (*info->format == 'p')
		size = (ft_numberlen((unsigned long long)va_arg(copy, void *), 16));
	else if (*info->format == 'd' || *info->format == 'i')
	{
		num = va_arg(copy, int);
		if (num < 0)
			size = (ft_numberlen(-(long long)num, 10));
		else
			size = (ft_numberlen(num, 10));
	}
	va_end(copy);
	return (size);
}
