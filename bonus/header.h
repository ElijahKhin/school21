/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:01:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/09 17:48:05 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct row_info
{
	const char *format;
	va_list	arg_ptr;
} t_rinfo;

int ft_printf(const char *format, ...);
int print_arg(char ch, va_list arg_ptr);
int ft_print_char(va_list arg_ptr);
int ft_print_str(va_list arg_ptr);

#endif

