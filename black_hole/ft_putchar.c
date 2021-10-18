/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:31:38 by fhiedi            #+#    #+#             */
/*   Updated: 2021/10/18 20:27:47 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main()
{
	int dig1;
	int dig2;
	int dig3;
	int counter;	

	counter = 0;
	dig1 = 0;
	dig2 = 1;
	dig3 = 2;

	while (dig1 !=8)
	{	
		while (dig2 != 9)
		{
			while (dig3 != 10)
			{
				ft_putchar(dig1 + '0');
				ft_putchar(dig2 + '0');
				ft_putchar(dig3 + '0');
				if (dig1 == 7 && dig2 == 8 && dig3 == 9)
					ft_putchar('\n');
				else
				{
				ft_putchar(',');
				ft_putchar(' ');
				}
				dig3++;
				counter++;
			}
			dig2++;
			dig3 = dig2 + 1;
		}
		dig1++;
		dig2 = dig1 + 1;
		dig3 = dig2 + 1;
	}
	
	printf("NUMBER OF UNIQUE COMBINATIONS: %d", counter);
	
	return (0);
}
