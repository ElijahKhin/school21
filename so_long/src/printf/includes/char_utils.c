/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:17:50 by fhiedi            #+#    #+#             */
/*   Updated: 2022/03/22 18:55:58 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_putstr(char *str, int arg_len)
{
	int	index;

	index = 0;
	while (str[index] && arg_len-- > 0)
		write(1, &str[index++], 1);
	return (index);
}

int	ft_strlen(char *str, int precision)
{
	int	index;

	index = 0;
	if (!str)
	{
		if (precision >= 6 || precision == -1)
			return (6);
		else
			return (precision);
	}
	while (str[index] != '\0' && (precision > index || precision == -1))
		index++;
	return (index);
}

int	ft_print_char(char ch)
{
	return (write(1, &ch, 1));
}

int	ft_print_str(char *str, int arg_len)
{
	if (!str)
		return (ft_putstr("(null)", arg_len));
	return (ft_putstr(str, arg_len));
}
