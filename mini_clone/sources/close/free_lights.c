/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:51:45 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:51:46 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <unistd.h>
#include <stdlib.h>

void	free_lights(t_lights **lights)
{
	t_lights		*start;
	t_lights		*next;

	console_put(RT_FREE_CAM);
	start = *lights;
	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
	*lights = NULL;
}
