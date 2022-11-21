/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:51:06 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:56:54 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define GNL_EOF 0
# define GNL_READ 1
# define GNL_ERROR -1
# include <stdlib.h>
# include <unistd.h>
# include <alias.h>

typedef struct s_fileinf
{
	int			fd;
	int			ret;
	char		*line;
	char		*line_cpy;
	t_bool		success;
}	t_fileinf;

typedef struct s_data
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
}	t_data;

typedef struct s_linedata
{
	char		*str;
	size_t		len;
	size_t		plen;
}	t_ldata;

/*
***	get next line
*/

int				get_next_line(int fd, char **line);
int				gnl_make(char **line, char **temp, char c);
int				gnl_checkbuf(char *tmp);
int				gnl_make_temp(char **temp, char *readbuf);

/*
***	utils
*/

int				gnl_strlen_nl(char *str);
void			*gnl_memcpy(char *dst, char *src, size_t n);
size_t			gnl_strlen_c(char *s, char c);
char			*gnl_strndup(char *s1, size_t len);
char			*gnl_strjoin(char *s1, char *s2);

#endif
