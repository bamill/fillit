/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:18:58 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 22:56:08 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static char		piece_char(char **piece)
{
	size_t		i;

	if (!piece)
		return (-1);
	i = 0;
	while (piece[i])
	{
		if (piece[i][0] != '.')
			return (piece[i][0]);
		i++;
	}
	return (-1);
}

void	unplace(char **piece, char **map)
{
	size_t	map_root;
	size_t	p_x;
	size_t	p_y;
	size_t	*p;
	char	p_al;
	
	if (!map || !piece)
		return ;
	map_root = (size_t)ft_strlen(map[0]);
	p_x = (size_t)ft_strlen(piece[0]);
	p_y = piece_y(piece);
	if ((p = (size_t*)(malloc(sizeof(size_t) * 2))))
	{
		p[0] = 0;
		p[1] = 0;
	}
	else
		return ;
	p_al = piece_char(piece);
	while (p[1] <= (map_root - p_y))
	{
		while (p[0] <= (map_root - p_x))
		{
			map[p[1]][p[0]] = map[p[1]][p[0]] == p_al ? '.' : map[p[1]][p[0]];
			p[0]++;
		}
		p[0] = 0;
		p[1]++;
	}
	ft_memdel((void**)&p);
	return ;
}
