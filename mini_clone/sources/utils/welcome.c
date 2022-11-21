/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:34:39 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:34:40 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print_welcome(void)
{
	ft_putstr_fd("miniRT: My first RayTracer with miniLibX\n", 1);
	ft_putstr_fd("usage:	./minirt file.rt\n", 1);
	ft_putstr_fd("flags:	--save\n", 1);
	exit(EXIT_SUCCESS);
}
