/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:05:44 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:05:46 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*str;
	size_t	len;

	len = ft_strlen((char *)s1) + 1;
	str = (char *)malloc(len);
	if (str == NULL)
		return (NULL);
	return ((char *)ft_memcpy(str, s1, len));
}
