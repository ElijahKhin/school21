/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:29:27 by sworker           #+#    #+#             */
/*   Updated: 2022/02/08 16:40:32 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_list_flags
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precise;
}				t_list_flags;

int				ft_printf(const char *str, ...);
int				ft_print_arg(t_list_flags flags, char c, va_list argv);
int				ft_print_int(t_list_flags flags, va_list argv);
int				ft_print_ptr(t_list_flags flags, va_list args);
int				ft_print_unsigned_int(t_list_flags flags, va_list args);
int				ft_print_percent(t_list_flags flags);
int				ft_print_other(char c, t_list_flags flags);
int				ft_print_char(t_list_flags flags, va_list args);
int				ft_print_hex(char *array_hex, t_list_flags flags, va_list args);
int				ft_print_str(t_list_flags flags, va_list args);
char			*ft_convert_pointer(char *array_hex, unsigned long long number);
int				ft_add_width(char c, int width);
int				ft_check_num(unsigned long long number, int size);
char			*ft_utoa(unsigned int n);
t_list_flags	default_flags(void);
int				is_flag(char c);
t_list_flags	parser(t_list_flags flags, const char *str, va_list args);
int				main_loop(const char	*str, t_list_flags flags, va_list args);
#endif
