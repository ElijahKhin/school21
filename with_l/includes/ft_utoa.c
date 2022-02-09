/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:34:13 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:34:14 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_num(long n)
{
	int	i;

	i = 1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		size;
	long	num;

	num = n;
	size = count_num(num);
	if (n == 0)
		return (str = ft_strdup("0"));
	str = malloc(sizeof(char) * size);
	if (!str)
		return (0);
	str[--size] = '\0';
	while (num / 10 >= 1)
	{
		str[--size] = (num % 10) + '0';
		num /= 10;
	}
	str[0] = (num % 10) + '0';
	return (str);
}
