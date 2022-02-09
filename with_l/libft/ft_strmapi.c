/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:25:37 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:25:40 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	char	*res;
	int		i;

	if (!f || !s)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	res = p;
	i = 0;
	while (*s)
	{
		*p = f(i, *s);
		p++;
		i++;
		s++;
	}
	*p = '\0';
	return (res);
}
