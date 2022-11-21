/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:52:35 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:52:36 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H
# include <scene.h>

t_thr_data	*thread_init(t_scene *scene, int idx, t_real *completion,
				pthread_mutex_t *lock);
t_bool		material_init(t_material *mat);

#endif
