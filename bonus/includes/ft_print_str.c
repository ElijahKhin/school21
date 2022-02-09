/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:33:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/09 17:45:55 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "../libft/libft.h"

int ft_print_str(va_list arg_ptr)
{
	char *str;

	str = va_arg(arg_ptr, char *);
	return (ft_putstr(str));
}
