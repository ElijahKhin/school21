/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:03:47 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:03:48 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str, int *num)
{
	int		index;
	long	ret;

	index = 0;
	ret = 0;
	if (!str)
		return (0);
	if (!num)
		return (-1);
	if (str[index] == '-')
		index++;
	while (str[index] && ft_isalnum(str[index]))
	{
		ret = 10 * ret + (str[index] - '0');
		index++;
	}
	if (index == 0 || (str[0] == '-' && index == 1))
		return (0);
	if (str[0] == '-')
		*num = -ret;
	else
		*num = ret;
	return (index);
}
