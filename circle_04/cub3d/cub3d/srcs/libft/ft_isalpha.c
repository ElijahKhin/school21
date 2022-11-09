/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:04:20 by scoach            #+#    #+#             */
/*   Updated: 2021/05/07 22:12:50 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper_bonus(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

static int	ft_islower_bonus(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper_bonus(c) || ft_islower_bonus(c))
		return (1);
	return (0);
}
