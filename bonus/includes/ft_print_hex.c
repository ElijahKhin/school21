/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:17:08 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/11 15:06:14 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"


int	recursion_hex(unsigned long int arg, char ch)
{
	static int	printed;
	char *hex;
	char printed_ch;

	hex = "0123456789abcdef";
	printed = 0;
	if (arg / 16)
		printed = recursion_hex(arg / 16, ch);
	if (ch >= 65 && ch <= 90)
		printed_ch = ft_toupper(hex[arg % 16]);
	else
		printed_ch = hex[arg % 16];
	printed += write(1, &printed_ch, 1);
	return (printed);
}

int		ft_print_hex(unsigned long int arg, char ch)
{
	int		printed;

	printed = 0;
	if (ch == 'p')
		printed = write( 1, "0x", 2);
	printed += recursion_hex(arg, ch);
	return (printed);
}
