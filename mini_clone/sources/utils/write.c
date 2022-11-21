/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:34:43 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:34:44 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <unistd.h>

void	write_bin(t_bool *check, int fd, void *value, int size)
{
	if (*check == false)
		return ;
	if (write(fd, &value, size))
		return ;
	else
		*check = false;
}

void	write_def(t_bool *check, int fd, void *value, int size)
{
	if (*check == false)
		return ;
	if (write(fd, value, size))
		return ;
	else
		*check = false;
}
