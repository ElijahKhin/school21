/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:04:10 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:04:11 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int i)
{
	int	j;

	j = 0;
	if (i <= 0)
		j = 1;
	while (i)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

static char	*ft_fillstring(char *str, long long x, int j)
{
	size_t	i;

	if (x < 0)
	{
		str[0] = '-';
		x *= -1;
	}
	while (x)
	{
		i = x;
		i %= 10;
		j--;
		str[j] = i + '0';
		x /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			j;
	long long	k;

	j = ft_count(n);
	k = n;
	if (k == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	if (k == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[j] = '\0';
	return (ft_fillstring(str, k, j));
}
