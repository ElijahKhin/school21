/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:37:01 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:37:02 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>
#include <error.h>
#include <init.h>
#include <utils.h>
#include <bitmap.h>
#include <libft.h>
#include <parse.h>

int	main(int argc, char *argv[])
{
	t_scene		*scene;

	if (argc < 2 || argc > 5)
		print_welcome();
	scene = scene_allocate();
	if (scene == NULL)
		error_exit(ERR_SCENE_ALLOC_FAILED);
	if (scene_init(scene, argv[1]) == false)
		error_free_and_exit(scene, ERR_SCENE_INIT_FAILED);
	if (buffer_init(scene) == false)
		error_free_and_exit(scene, ERR_MLX_INIT_FAILED);
	if (ft_match(argv[2], RT_SAVE_SS))
		scene->viewport = shaded;
	if (update(scene) == false)
		error_free_and_exit(scene, ERR_SCENE_FAILURE);
	if (scene->viewport == shaded)
		save_bmp(&scene->main, "Screenshot.bmp");
	hook_init(scene);
	return (1);
}
