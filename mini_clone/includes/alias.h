/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:50:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:50:42 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H
# define M_EPSILON 1e-8
# define M_INFINITY 1.0e30f
# define COLOR_SIZE 8
# define DELIM_SPACE " \t\n\v\f\r"
# define DELIM_QUOT "\""
# define DELIM_COMMA ","
# define PI_2 6.28318531

/*
**	real number
*/
typedef double	t_real;

/*
**	boolean for return values
*/
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

#endif
