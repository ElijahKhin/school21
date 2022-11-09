/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:15:09 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 10:53:19 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charinstr(const char *str, int c)
{
	int		run;
	char	twin;

	twin = (unsigned char)c;
	run = 0;
	while (str[run])
	{
		if (str[run] == twin)
			return (1);
		run++;
	}
	if (str[run] == twin)
		return (1);
	return (0);
}
