/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:01:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/03/09 15:42:45 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct arg_info
{
	const char *format;
	int width;
	int printed;
} t_arginfo;


void	check_flags(char *format, t_arginfo *arginfo);
int get_width(char *format);
int recusion_hex(unsigned long int  arg, char ch);
int ft_print_hex(unsigned long int arg, char ch);
int ft_printf(const char *format, ...);
int def_spec(char ch, va_list arg_ptr);
int ft_print_char(char ch);
int ft_print_str(char *str);
int ft_print_nbr(int nbr);
int ft_unsigned_nbr(unsigned int nbr);

#endif

