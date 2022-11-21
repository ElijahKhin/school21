/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:56:26 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:56:27 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>
#include <unistd.h>

t_bool	construct(t_shapes **list)
{
	t_shapes	*cur_shape;

	cur_shape = *list;
	while (cur_shape != NULL)
	{
		jump_construct(cur_shape);
		cur_shape = cur_shape->next;
	}
	return (true);
}
