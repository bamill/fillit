/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:27:57 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/08 21:58:28 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *b, const char *l, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(int c);
void				ft_putstr(const char *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_lstfold(t_list *lst, void *(*f)(void *e1, void *e2));
void				*ft_addi_pt(void *p1, void *p2);
void				ft_lstprint(t_list *lst, void (*f)(void*));
void				ft_putnbr_pt(void *n);
void				*ft_minus_pt(void *p1, void *p2);
t_list				*ft_lstfilter(t_list *lst, int (*f)(void *));
t_list				*ft_lstfilter_l(t_list *lst, int (*f)(t_list *));
t_list				*ft_square_lst(t_list *lst);
int					ft_is_odd(void *data);
int					ft_lst_is_odd(t_list *lst);
int					ft_is_even(void *data);
int					ft_lst_is_even(t_list *lst);
int					ft_lst_is_singleton(t_list *lst);
int					ft_lst_is_compound(t_list *lst);
void				*ft_lstfirst(t_list *lst);
t_list				*ft_lstrest(t_list *lst);
void				*ft_lst_last(t_list *lst);
t_list				*ft_lst_butlast(t_list *lst);
t_list				*ft_lstrev(t_list *lst);
void				ft_list_remove_if(t_list **begin, void *d, int (*cmp)());
int					ft_sumofsq_lst(t_list *lst);
int					ft_gt_pt(void *e1, void *e2);
t_list				*ft_lstcpy(t_list *lst);
size_t				ft_lstlen(t_list *lst);
t_list				*ft_strsplitlst(const char *s, char c);
t_list				*ft_strtolst(char *str);
t_list				*ft_lsttake(t_list *lst, size_t count);
t_list				*ft_lstdrop(t_list *lst, size_t count);
t_list				*ft_lst_rot(t_list *lst, int i);

#endif
