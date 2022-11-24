/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:50 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:27:51 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <error.h>

t_bool	light_push_back(t_lights **list, t_lights *light)
{
	t_lights		*start;

	start = *list;
	if (start)
	{
		while (start->next)
			start = start->next;
		start->next = light;
		if (start->next == NULL)
			return (error_msg(ERR_ALLOC_LIGHT));
	}
	else
	{
		*list = light;
		if (*list == NULL)
			return (error_msg(ERR_ALLOC_LIGHT));
		start = *list;
	}
	return (true);
}
