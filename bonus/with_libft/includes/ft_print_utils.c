/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:59 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:34:01 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_check_num(unsigned long long number, int size)
{
	int	count;

	count = 0;
	while (number > 0)
	{
		number /= size;
		count++;
	}
	return (count);
}

int	ft_add_width(char c, int width)
{
	int	i;

	i = -1;
	while (++i < width)
		ft_putchar_fd(c, 1);
	return (i);
}

char	*ft_convert_pointer(char *array_hex, unsigned long long number)
{
	int		len_hex;
	int		count_num;
	char	*str;

	len_hex = ft_strlen(array_hex);
	count_num = ft_check_num(number, len_hex);
	str = (char *)malloc(sizeof(char) * (count_num + 1));
	if (!str)
		return (NULL);
	str[count_num] = '\0';
	while (--count_num)
	{
		str[count_num] = array_hex[number % len_hex];
		number /= len_hex;
	}
	if (count_num == 0)
		str[count_num] = array_hex[number % len_hex];
	return ((char *)str);
}
