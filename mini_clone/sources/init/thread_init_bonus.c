/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:20:34 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:20:35 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <libft.h>

t_thr_data	*thread_init(t_scene *scene, int idx, t_real *completion,
	pthread_mutex_t *lock)
{
	t_thr_data	*data;

	data = (t_thr_data *)ft_calloc(1, sizeof(t_thr_data));
	if (data == NULL)
		return (NULL);
	*completion = 0;
	data->scene = scene;
	data->idx = idx;
	data->completion = completion;
	data->lock = lock;
	return (data);
}
