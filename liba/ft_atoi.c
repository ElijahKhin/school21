/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:42:43 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/19 21:28:07 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	run;
	int	sign;
	int	ret;

	run = 0;
	sign = 1;
	ret = 0;
	while (str[run] == ' ' || str[run] == '\t' || str[run] == '\n'
		|| str[run] == '\v' || str[run] == '\r' || str[run] == '\f')
		run++;
	if (str[run] == '-' || str[run] == '+')
	{
		if (str[run++] == '-')
			sign *= -1;
	}
	while (str[run] >= 48 && str[run] <= 57)
	{
		ret = ret * 10 + (str[run++] - '0');
	}
	return (ret * sign);
}
