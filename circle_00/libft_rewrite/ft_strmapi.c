/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:59:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 14:25:10 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result_str;

	i = -1;
	result_str = malloc(ft_strlen(s) + 1);
	if (!result_str)
		return (NULL);
	while (s[++i])
		result_str[i] = f(i, s[i]);
	result_str[i] = '\0';
	return (result_str);
}
