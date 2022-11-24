/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:03 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:27:05 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>

static t_camlist	*new_cam(t_camera *cam, int id)
{
	t_camlist		*element;

	element = (t_camlist *)ft_calloc(1, sizeof(t_camlist));
	if (element == NULL)
		return (NULL);
	element->id = id;
	element->cam = cam;
	element->next = NULL;
	return (element);
}

t_bool	cam_push_back(t_camlist **list, t_camera *cam, int id)
{
	t_camlist		*start;

	if (!cam)
		return (error_msg(ERR_CAM_ADD));
	start = *list;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = new_cam(cam, id);
		if (start->next == NULL)
			return (error_msg(ERR_ALLOC_CAM));
	}
	else
	{
		*list = new_cam(cam, id);
		if (*list == NULL)
			return (error_msg(ERR_ALLOC_CAM));
	}
	return (true);
}
