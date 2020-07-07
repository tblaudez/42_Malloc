/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaudez <tblaudez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:45:47 by tblaudez          #+#    #+#             */
/*   Updated: 2020/07/07 19:29:00 by tblaudez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct s_list t_list;
struct s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *link, void (*f)(t_list *elem));

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);

size_t	ft_strlen(const char *s);

/*
** ft_fprintf() 
*/
# define FLAGS		"#0- +"
# define LETTERS	"sSdoxcCpub"

# define HASH		(list->flags & (1 << 4))
# define ZERO		(list->flags & (1 << 3))
# define MINUS		(list->flags & (1 << 2))
# define SPACE		(list->flags & (1 << 1))
# define PLUS		(list->flags & 1)

typedef struct		s_printf
{
	char			flags;
	char			modif;
	int				width;
	int				preci;
}					t_printf;

void				ft_fprintf(int fd, char *format, ...);

char				*apply_hash(char *str, char conv);
char				*apply_zero(char *str, char conv);
char				*apply_minus(char *str);
char				*apply_space(char *str, char conv);
char				*apply_plus(char *str, char conv);

char				*calculate_unicode(char *ret, wchar_t value);
char				*get_string(va_list ap);
char				*get_char(va_list ap);
char				*get_pointer(va_list ap);

char				*get_decimal(va_list ap);
char				*get_hexa(va_list ap);
char				*get_octal(va_list ap);
char				*get_unsigned(va_list ap);
char				*get_binary(va_list ap);

int					find_end(char *format);
t_printf			*get_list_printf(int type);
int					set_modif(char *format);
char				*check_flags(char *format);
int					check_colors(char *format, int fd, int *i);
char				*apply_width(char *str, char conv);

char				*ft_uitoabase(uintmax_t nbr, int base);
int					ft_unbrdig(uintmax_t nbr, int base);

#endif