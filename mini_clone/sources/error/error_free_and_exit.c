/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_and_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:53:25 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <events.h>
#include <minirt.h>

t_bool	error_free_and_exit(t_scene *scene, char *message)
{
	console_put(message);
	free_and_exit(scene);
	return (false);
}
