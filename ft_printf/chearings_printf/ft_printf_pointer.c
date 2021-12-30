/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:11:04 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/26 16:11:04 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(unsigned long long	nb, char	*base,
						char	*p, int	count)
{
	if (nb > 0)
	{
		count++;
		ft_putpointer(nb / 16, base, p, count);
	}
	p[15 - count + 1] = base[(nb % 16)];
	count--;
}

int	ft_printf_pointer(unsigned long long	nbr)
{
	char		p[16];
	int			i;
	static int	count;
	int			returner;

	returner = 2;
	count = 0;
	i = 0;
	while (i < 16)
		p[i++] = '0';
	ft_putpointer(nbr, "0123456789abcdef", p, count);
	i = 0;
	while (p[i] == '0')
		i++;
	if (i == 17)
	{
		write(1, "0", 1);
		return (3);
	}
	while (i < 16)
	{
		write(1, &p[i++], 1);
		returner++;
	}
	return (returner);
}
