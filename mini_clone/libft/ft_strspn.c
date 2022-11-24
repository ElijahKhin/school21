/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:06:27 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:06:28 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str, const char *accept)
{
	size_t	ret;

	ret = 0;
	if (accept[0] == '\0')
		return (ft_strlen(str));
	while (str[ret] != '\0')
	{
		if (ft_strchr(accept, str[ret]))
			return (ret);
		ret++;
	}
	return (ft_strlen(str));
}

size_t	ft_strspn(const char *str, const char *accept)
{
	size_t	size;
	size_t	ret;

	ret = 0;
	size = 0;
	while (str[size] != '\0')
	{
		if (!(ft_strchr(accept, str[size])))
			return (ret);
		else
			ret++;
		size++;
	}
	return (0);
}
