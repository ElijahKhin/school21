/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:01:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/03/23 19:06:27 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct arg_info
{
	const char	*format;
	va_list		arg_ptr;
	char		spec;
	int			width;
	int			precision;
	int			printed;
	int			index;
	int			left_padding;
	int			zero_padding;
	int			sharp;
	int			plus;
	int			space;
	int			arg_len;
	int			minus;
	int			zero;
	int			padding;
}	t_arginfo;

int		ft_printf(const char *format, ...);
void	get_info(t_arginfo *info);
void	flag_left(t_arginfo *info);
void	flag_plus(t_arginfo *info);
void	flag_zero(t_arginfo *info);
void	flag_space(t_arginfo *info);
void	flag_sharp(t_arginfo *info);
void	width(t_arginfo *info);
void	precision(t_arginfo *info);
void	write_space_plus(t_arginfo *info);
void	arg_length(t_arginfo *info);
void	print_arg_one(t_arginfo *info);
void	print_arg_two(t_arginfo *info);
void	padding_one(t_arginfo *info);
void	padding_two(t_arginfo *info);
void	appendix(t_arginfo *info);
void	check_print(t_arginfo *info);
int		ft_strlen(char *str, int precision);
int		num_len(long long n, int base, t_arginfo *info);
int		ft_isdigit(int c);
int		ft_print_char(char ch);
int		ft_print_str(char *str, int arg_len);
int		recusion_hex(unsigned long int arg, char ch, t_arginfo *info);
int		ft_print_hex(unsigned long int arg, char ch, t_arginfo *info);
int		ft_print_nbr(int nbr, t_arginfo *info);
int		ft_unsigned_nbr(unsigned int nbr, t_arginfo *info);
int		ft_putstr(char *str, int arg_len);
int		ft_toupper(int c);
int		precision_unbr(t_arginfo *info);
int		ox(t_arginfo *info);

#endif
