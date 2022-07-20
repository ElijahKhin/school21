/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:36:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/20 20:34:24 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *tmp1;
	unsigned char *tmp2;
	int	calc;
	

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	
	if (n == 0)
		return (0);
	while (*tmp1 && *tmp2 && n > 0)
	{
		calc = *tmp1++ - *tmp2++;
		if (calc != 0)
			return (calc);
		n--;
	}
	if (n > 0)
		calc = *tmp1 - *tmp2;
	return(calc);
}
