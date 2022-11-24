/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cameras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:51:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:51:42 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>
#include <unistd.h>

void	free_cameras(t_camlist **list)
{
	t_camlist		*start;
	t_camlist		*next;

	console_put(RT_FREE_CAM);
	start = *list;
	while (start)
	{
		next = start->next;
		free(start->cam);
		free(start);
		start = next;
	}
	*list = NULL;
}
