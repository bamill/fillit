/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:25:44 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 17:48:20 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# define SIZE 20

void					alphabeterizer(t_list *pieces, size_t s, size_t n);
t_list					*piece_trim_lst(t_list *lst);
char					**piece_trim(char **piece);
char					**solver(t_list **pieces);
void					place(char **piece, char **map, size_t x, size_t y);
void					unplace(char **piece, char **map);
int						fits(char **piece, char **map, size_t x, size_t y);
void					print_map(char **map);
int						ft_nearest_sqr(int nb);
t_list					*ft_stomultistr(t_list *lst);
t_list					*ft_lst_rot(t_list *lst, int i);
int						verif(char *str);
size_t					piece_y(char **piece);
void					ft_super_lstprint(t_list *lst, void (*f)(char**));
int						fitter(char **piece, char **map, size_t x, size_t y);

#endif
