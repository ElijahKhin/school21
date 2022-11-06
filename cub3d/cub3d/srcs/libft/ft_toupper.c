/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:14:48 by scoach            #+#    #+#             */
/*   Updated: 2021/05/07 16:14:49 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower_bonus(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower_bonus(c))
		return (c - 32);
	return (c);
}
