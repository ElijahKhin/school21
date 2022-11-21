/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:54:31 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:54:32 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <scene.h>
#include <jump_tables.h>
#include <stdio.h>

int	key_handle(t_key key, t_scene *scene)
{
	if (key != Enter && scene->viewport == shaded)
		scene->viewport = flat;
	if (!jump_key(scene, key))
		return (1);
	if (update(scene) == false)
		free_and_exit(scene);
	return (1);
}
