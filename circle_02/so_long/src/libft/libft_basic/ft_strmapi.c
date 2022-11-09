/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:36:38 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/23 21:32:37 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	run;
	char			*ret;

	if (s == 0 || f == 0)
		return (NULL);
	run = 0;
	ret = (char *)malloc(sizeof(char) * lb_strlen((char *)s) + 1);
	if (!ret)
		return (NULL);
	while (s[run])
	{
		ret[run] = f(run, s[run]);
		run++;
	}
	ret[run] = '\0';
	return (ret);
}
