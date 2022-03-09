/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:25:09 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/17 19:04:01 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int get_width(char *format)
{
	int width;
	int runner;

	if (!ft_isdigit(format[1]))
		return (0);
	runner = 0;
	width = (format[++runner] - 48) * 10;
	while (ft_isdigit(format[++runner]))
		width = (width + (format[runner] - 48)) * 10;
	return (width/10);
}
