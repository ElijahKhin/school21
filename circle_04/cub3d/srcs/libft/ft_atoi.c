/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 10:50:56 by scoach            #+#    #+#             */
/*   Updated: 2022/03/17 18:46:52 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	atoi_error(void)
{
	write(2, "Error\nft_atoi\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int		neg;
	ssize_t	num;
	size_t	i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
		if (!ft_isdigit(str[i]))
			atoi_error();
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + neg * (str[i++] - '0');
		if (num < -2147483648 || num > 2147483647)
			atoi_error();
	}
	neg = num;
	return (neg);
}
