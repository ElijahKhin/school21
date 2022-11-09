/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:50:57 by scoach            #+#    #+#             */
/*   Updated: 2021/05/11 17:27:00 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n *= -1;
	else
		ft_putchar_fd('-', fd);
	if (n < -9)
	{
		ft_putnbr_fd((n / 10) * (-1), fd);
		ft_putnbr_fd((n % 10) * (-1), fd);
	}
	else
		ft_putchar_fd((n * (-1) + '0'), fd);
}
