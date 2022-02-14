/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfelwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:55:22 by tfelwood          #+#    #+#             */
/*   Updated: 2022/02/12 18:59:24 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_print_info
{
	const char	*format;
	char		flags;
	int			width;
	int			prec;
	int			count;
	va_list		args;
}	t_print_info;

int		ft_atoi(t_print_info *info);
int		ft_is_number(char mod);
int		ft_is_hex(char mod);
void	ft_input_format(t_print_info *info);
int		ft_get_size(t_print_info *info);
void	ft_print_modifier(t_print_info *info);
void	ft_print_format_mod(t_print_info *info);
int		ft_printf(const char *format, ...);

#endif
