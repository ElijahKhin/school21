/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:04:15 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 20:29:18 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_info(t_arginfo *info)
{
	flag_left(info);
	flag_plus(info);
	flag_zero(info);
	flag_space(info);
	flag_sharp(info);
	width(info);
	precision(info);
	info->spec = info->format[info->index];
	write_space_plus(info);
	arg_length(info);
}
