/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:52:26 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/25 16:39:00 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef LIBFT_H
# define LIBFT_H

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_isascii(int c);
int ft_isalnum(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2);
void ft_bzero(void *s, size_t n);
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
