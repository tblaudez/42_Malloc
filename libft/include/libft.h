/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:45:47 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/08 14:36:08 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);

size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
char    *ft_strcpy(char *dst, char *src);
char    *ft_strncpy(char *dst, char *src, size_t len);
char    *ft_strjoinfree(char *s1, char *s2);

#endif