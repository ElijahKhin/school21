/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:26:38 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:26:39 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	char	*p;

	d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	p = d;
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (p);
}
