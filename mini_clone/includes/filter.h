/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:51:00 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:51:02 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTER_H
# define FILTER_H
# include <buffer.h>
# include <color.h>

t_bool	f_sobel(t_buffer *in, t_buffer *out, t_rgb col);
t_real	sobel5x5(int idx1, int idx2, int xy);
t_real	sobel3x3(int idx1, int idx2, int xy);
t_rgb	sobel_sum3(t_rgb x, t_rgb y);
t_real	sobel_sum(t_real x, t_real y);

#endif
