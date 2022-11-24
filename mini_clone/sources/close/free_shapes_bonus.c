/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shapes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:51:57 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:51:58 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>
# include <stdlib.h>

void	free_bvh_nodes(t_bvhnode *root)
{
	int	idx;

	idx = 0;
	while (root->size && idx < 8)
	{
		if (root->branch[idx].depth != 0)
			free_bvh_nodes(&root->branch[idx]);
		else
			free(root->branch[idx].faces);
		idx += 1;
	}
	if (root->branch)
		free(root->branch);
	if (root->faces)
		free(root->faces);
}

void	free_trimesh(t_shapes *catch)
{
	t_trimesh	*mesh;

	mesh = catch->shape;
	free_bvh_nodes(&mesh->root);
	free(mesh->vert);
	free(mesh->face);
	free(mesh);
	free(catch);
}

void	free_shapes(t_shapes **shapes)
{
	t_shapes		*start;
	t_shapes		*next;

	console_put(RT_FREE_SHAPES);
	start = *shapes;
	while (start)
	{
		next = start->next;
		if (start->type == sh_trimesh)
			free_trimesh(start);
		else
		{
			free(start->shape);
			free(start);
		}
		start = next;
	}
	*shapes = NULL;
}

#endif
