/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:32:23 by fhiedi            #+#    #+#             */
/*   Updated: 2021/11/21 16:27:07 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len_1;
	int		len_2;

	if (!(s1) && !(s2))
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (size_t)(len_1 + len_2 + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len_1 + 1);
	ft_strlcat(ret + len_1, s2, len_2 + 1);
	return (ret);
}
