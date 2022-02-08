/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:32:13 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:32:14 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overlap(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *nptr)
{
	long long	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (*nptr != '\0' && ((*nptr >= 9 && *nptr <= 13) || *nptr == ' '))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr != '\0' && (*nptr >= 48 && *nptr <= 57))
	{
		if (nb > nb * 10 + (*nptr - '0') && nb != 214748364)
			return (ft_overlap(sign));
		nb = (nb * 10) + (*nptr - '0');
		nptr++;
	}
	return ((int)nb * sign);
}
