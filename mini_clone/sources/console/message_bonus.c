/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:52:45 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:52:46 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <libft.h>

void	console_putstr(char *message, char *str)
{
	ft_putstr_fd("[\033[1;33mminiRT\033[0m]: ", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd(" \033[4m", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\033[0m\n", 1);
}

void	console_put(char *message)
{
	ft_putstr_fd("[\033[1;33mminiRT\033[0m]: ", 1);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
}

void	console_putnn(char *message)
{
	ft_putstr_fd("[\033[1;33mminiRT\033[0m]: ", 1);
	ft_putstr_fd(message, 1);
}

#endif
