/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:14:06 by scoach            #+#    #+#             */
/*   Updated: 2022/03/18 16:39:16 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free_all(int fd, char ***rest, int key)
{
	int	i;

	if (*rest != NULL && fd >= 0)
	{
		free((*rest)[fd]);
		(*rest)[fd] = NULL;
		i = 0;
		while (i < 1024 && ((*rest)[i] == NULL || (*rest)[i][0] == '\0'))
			i++;
		if (i == 1024)
		{
			while (i > 0)
			{
				i--;
				if ((*rest)[i] != NULL)
				{
					free((*rest)[i]);
					(*rest)[i] = NULL;
				}
			}
			free(*rest);
			*rest = NULL;
		}
	}
	return (key);
}
