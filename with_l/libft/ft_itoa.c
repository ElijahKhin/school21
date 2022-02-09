/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:31:25 by sworker           #+#    #+#             */
/*   Updated: 2022/01/17 14:31:26 by sworker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_putsnbr(char *s, long int num)
{
	if (num < 10)
		*s = num + '0';
	else
	{
		ft_putsnbr(s + 1, num / 10);
		*s = num % 10 + '0';
	}
}

static void	ft_strev(char *s)
{
	int			i;
	int			j;
	char		temp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	i = ft_strlen(s);
	s[i] = '\0';
}

static char	*get_string(char *s, int num)
{
	char		*p;
	long int	temp;

	p = s;
	temp = num;
	if (temp < 0)
	{
		temp = temp * (-1);
		*s = '-';
		s++;
	}
	ft_putsnbr(s, temp);
	ft_strev(s);
	return (p);
}

char	*ft_itoa(int n)
{
	char		*s;

	s = (char *)malloc(sizeof(char) * 12);
	if (!s)
		return (NULL);
	ft_bzero(s, 12);
	s = get_string(s, n);
	return (s);
}
