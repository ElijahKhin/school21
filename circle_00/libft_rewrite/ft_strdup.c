/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:39:42 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/07 19:38:16 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len_of_s1;
	char	*ptr_to_s1;

	i = -1;
	len_of_s1 = ft_strlen(s1);
	ptr_to_s1 = malloc(sizeof(char) * (len_of_s1 + 1));
	if (!ptr_to_s1)
		return (NULL);
	while (len_of_s1 > i++)
		ptr_to_s1[i] = s1[i];
	return (ptr_to_s1);
}
