/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:35:58 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/10 15:48:54 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putstr(char *s);
int	ft_putnbr_u(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_printf_hex(unsigned int x, char c);
int	ft_printf(const char *format, ...);
#endif
