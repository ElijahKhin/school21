/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:04:21 by fhiedi            #+#    #+#             */
/*   Updated: 2022/01/23 17:17:34 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);	
}

int main(void)
{
	char *array;

	array = "12461234678236478ghjdsfb21gf4byfbwq4ufby4fb18^%&%$%^^^*";
	
	while (*array)
	{
		printf("%c --- %d\n", *array, ft_isalpha(*array));
		array++;
	}
	return (0);
}
