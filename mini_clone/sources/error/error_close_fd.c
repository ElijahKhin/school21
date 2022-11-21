/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_close_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:10 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:53:11 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <unistd.h>
#include <libft.h>

t_bool	error_close_fd(int fd, char *message)
{
	close(fd);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	return (false);
}
