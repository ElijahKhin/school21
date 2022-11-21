/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:28 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:53:29 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <libft.h>

t_bool	error_line(char *line)
{
	ft_putstr_fd("  Line: \033[1;34m", 1);
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\n\033[0m", 1);
	return (false);
}

t_bool	error_msg(char *message)
{
	ft_putstr_fd("\033[1;31mError\033[0m\n  ", 1);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	return (false);
}
