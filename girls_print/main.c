/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:50:57 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/11 16:40:01 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main(void)
{
/*	unsigned int test = LONG_MIN;
	char *p;

	p = NULL;

	printf("%d   ", ft_printf("%c ", 'H'));
	printf("%d\n\n", printf("%c ", 'H'));

	printf("%d   ", ft_printf("NULL %s NULL", NULL));
	printf("%d\n\n", printf("NULL %s NULL", NULL));
	
	printf("%d   ", ft_printf("%d ", -1000));
	printf("%d\n\n", printf("%d ", -1000));

	printf("%d   ", ft_printf("%u ", -1000));
	printf("%d\n", printf("%u ", -1000));*/

	ft_printf("%x", LONG_MIN);
	
	return (0);
}
