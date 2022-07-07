/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:51:39 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/19 21:36:49 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	counter;
	unsigned char	left;
	unsigned char	right;

	counter = 0;
	while ((s1[counter] != '\0' || s2[counter] != '\0') && counter < n)
	{
		left = s1[counter];
		right = s2[counter];
		if ((left < right) || (left > right))
		{
			return (left - right);
		}
		counter++;
	}
	return (0);
}
