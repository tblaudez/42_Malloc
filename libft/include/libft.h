/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:45:47 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/13 18:09:04 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

# define MAX(x, y)  (x >= y ? x : y)
# define MIN(x, y)  (x <= y ? x : y)
# define FREE_L		0x01
# define FREE_R		0x02


void		*ft_memset(void *s, int c, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);

size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
char    	*ft_strcpy(char *dst, const char *src);
char    	*ft_strncpy(char *dst, const char *src, size_t len);
char    	*ft_strjoinfree(const char *s1, const char *s2, char flags);
char    	*ft_strnjoinfree(const char *s1, const char *s2, size_t size, char flags);
char    	*ft_strdup(const char *s1);
char    	*ft_strndup(const char *s1, size_t size);
char		*ft_strreplace(char *str, const char *p1, const char *p2);
char		*ft_strreplaceone(char *str, const char *p1, const char *p2);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnew(size_t size);

int			ft_digitcount(int nbr, const int base);
char		*ft_itoabase(int value, const int base);

void		ft_printf(char *format, ...);

#endif