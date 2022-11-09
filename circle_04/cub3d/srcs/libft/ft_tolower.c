/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:14:40 by scoach            #+#    #+#             */
/*   Updated: 2021/05/07 16:14:42 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper_bonus(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper_bonus(c))
		return (c + 32);
	return (c);
}
