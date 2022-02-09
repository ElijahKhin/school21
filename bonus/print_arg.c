/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:57:29 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/09 17:59:17 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int print_arg(char ch, va_list arg_ptr)
{
	int printed;

	printed = 0;
	if (ch == 'c')
		printed += ft_print_char(arg_ptr);
	if (ch == 's')
		printed += ft_print_str(arg_ptr);
	return (printed);
}
