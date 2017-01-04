/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:25:44 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/03 17:20:54 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# define SIZE 20

typedef	struct			s_tetris
{
	char				**content;
	size_t				content_size;
	int					*dims;
	int					type;
	struct s_tetris		*next;
}						t_etris;

void	alphabeterizer(t_list *pieces, size_t s, size_t n);

#endif
