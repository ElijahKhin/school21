/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:14:13 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/07 19:30:51 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_convert_to_str(char **itoa, int n)
{
	static int	index;

	index = 0;
	if (n < 0)
	{
		(*itoa)[index++] = '-';
		n *= -1;
	}
	if (n >= 10)
		recursive_convert_to_str(itoa, n / 10);
	(*itoa)[index++] = n % 10 + 48;
	(*itoa)[index] = '\0';
}

char	*ft_itoa(int n)
{
	char	*itoa;

	if (n == MIN_INT)
		return (ft_substr("-2147483648", 0, 12));
	itoa = malloc(12);
	recursive_convert_to_str(&itoa, n);
	return (itoa);
}
