/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:51:53 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:51:54 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <minirt.h>
# include <shapes.h>
# include <stdlib.h>

void	free_shapes(t_shapes **shapes)
{
	t_shapes		*start;
	t_shapes		*next;

	console_put(RT_FREE_SHAPES);
	start = *shapes;
	while (start)
	{
		next = start->next;
		free(start->shape);
		free(start);
		start = next;
	}
	*shapes = NULL;
}

#endif
