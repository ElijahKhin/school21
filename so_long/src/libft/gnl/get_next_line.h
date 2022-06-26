/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:12:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/25 17:02:07 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		iter(char *join);
char	*get_short_join(char *join);
char	*get_ret_string(char *join);
char	*get_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	gnl_strlen(char *s);

#endif
