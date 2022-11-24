/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:35 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:53:36 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <libft.h>

t_bool	warning_line(char *line, char *message)
{
	ft_putstr_fd("\033[1;33mWarning:\n\033[4;33m  ", 1);
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\033[0m\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n\n", 1);
	return (true);
}

t_bool	warning_msg(char *message)
{
	ft_putstr_fd("\033[1;33mWarning:\n\033[0m  ", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	return (true);
}
