/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:46:23 by nrouzeva          #+#    #+#             */
/*   Updated: 2018/05/25 11:31:33 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include "unistd.h"
# include "../../printf/ft_printf.h"

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(char *str);
char				*ft_itoa(long long n);
char				*ft_itoa_ull(unsigned long long n, int base);
char				*ft_itoa_base(long long n, int base, char *str2);
char				*ft_itoa_hexa(unsigned long long n, int base, char *str2);
void				ft_print_addr(unsigned long long n);
char				*ft_strjfri(char const *s1, char const *s2, int opt);
void				ft_bzero(void *s, size_t n);
double				ft_atof(const char *str);

int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *str, const char *str2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
size_t				ft_strlen(const char	*str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_strdel(char **as);
char				*ft_strdup(char *str);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				**ft_strsplit(char const *s, char c);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strstr(const char *str, const char *str2);
char				*ft_strstr(const char *str, const char *str2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strclr(char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

int					ft_memcmp(const void *s1, const void *s2, size_t len);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				ft_putnbr(int n);
void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);

int					ft_sqrt(int nb);
int					ft_wd_count(char const *s, char c);
int					ft_len_number(long long n, int base);
int					ft_len_number_ull(unsigned long long n, int base);
char				*ft_split_word(char const *s, char c);
void				ft_foreach(int *tab, int length, void(*f)(int));
int					get_next_line(int const fd, char **line);
void				ft_tabdel(void **tab, int height);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_lstadd(t_list **alst, t_list *news);
void				ft_lst_pushback(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_del(void *d, size_t size);

#endif
