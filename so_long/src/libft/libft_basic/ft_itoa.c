/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:16:24 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/03 16:42:38 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nm_len(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}

int	ec(int n)
{
	if (n == -2147483648)
		return (1);
	return (0);
}

char	*ft_end(int n, int run, int size)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (size_t)(size + 1));
	if (!ret)
		return (NULL);
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		ret[run++] = '-';
		size--;
		if (ec(n))
			n++;
		n *= -1;
	}
	while (n > 0)
	{
		ret[run++] = n / ft_recursive_power(10, size - 1) + 48;
		n %= ft_recursive_power(10, size - 1);
		size--;
		while (n == 0 && size-- != 0)
			ret[run++] = 0 + 48;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		run;
	int		size;
	int		was;
	char	*ret;

	run = 0;
	size = nm_len(n);
	was = ec(n);
	if (ec(n))
		size = 11;
	ret = ft_end(n, run, size);
	if (was)
	{
		ret[10] = '8';
		ret[11] = '\0';
	}
	else
		ret[size] = '\0';
	return (ret);
}
