/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:01:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/14 19:09:30 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct row_info
{
	const char *format;
	va_list	arg_ptr;
} t_rinfo;


int	*check_flags(char *format);
int get_width(char **format);
int recusion_hex(unsigned long int  arg, char ch);
int ft_print_hex(unsigned long int arg, char ch);
int ft_printf(const char *format, ...);
int print_arg(char ch, va_list arg_ptr);
int ft_print_char(char ch);
int ft_print_str(char *str);
int ft_print_nbr(int nbr);
int ft_unsigned_nbr(unsigned int nbr);

#endif

