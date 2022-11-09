/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:08:10 by scoach            #+#    #+#             */
/*   Updated: 2021/05/16 18:46:09 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*d;

	d = b;
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(d + i) = (unsigned char)c;
		i++;
	}
	return (d);
}
