/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:01:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/08 20:02:46 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct row_info
{
	const char *format;
	va_list	arg_ptr;
} t_rinfo;

#endif

