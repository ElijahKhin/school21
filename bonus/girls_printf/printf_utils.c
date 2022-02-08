/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfelwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:55:59 by tfelwood          #+#    #+#             */
/*   Updated: 2021/12/25 21:56:07 by tfelwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_number(char mod)
{
	return (mod == 'x' || mod == 'X' || mod == 'd' || mod == 'i'
		|| mod == 'u');
}

int	ft_is_hex(char mod)
{
	return (mod == 'x' || mod == 'X' || mod == 'p');
}

int	ft_atoi(t_print_info *info)
{
	int	num;

	num = 0;
	while (*info->format >= '0' && *info->format <= '9')
	{
		num = num * 10 + *info->format - '0';
		++info->format;
	}
	return (num);
}
