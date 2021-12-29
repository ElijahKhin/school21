/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:11:11 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/26 16:11:11 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
int	ft_printf_pointer(unsigned long long	nbr);
int	ft_putnbr_U(unsigned int	nb);
int	ft_putnbr(int	nb);
int	ft_printf_hex(unsigned int	x, char	c);
int	ft_printf(const char *format, ...);
#endif
