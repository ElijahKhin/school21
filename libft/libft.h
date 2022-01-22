/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:02:47 by fhiedi            #+#    #+#             */
/*   Updated: 2022/01/18 17:35:28 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct kill_fucking_split{
	int	junk;
	int	real_row_length;
	int	jump_to_next_row;
}	t_kill_split;

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
void	ft_putchar_fd(char c, int ft);
void	ft_putstr_fd(char *s, int ft);
void	ft_putendl_fd(char *s, int ft);
void	ft_putnbr_fd(int n, int ft);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memset(void *b, int c, size_t n);
void	*ft_memchr(void *s, int c, size_t n);
void	*ft_memcpy(void *strA, const void *strB, size_t n);
void	*ft_memmove(void *strA, void *strB, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_isalnum(int c);
int		ft_atoi(const char *str);
int		ft_strlen(char const *str);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
