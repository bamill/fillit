/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:18:58 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 21:37:06 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static char		piece_char(char **piece)
{
	int		i;

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
	int	map_root;
	int	p_x;
	int	p_y;
	int	*p;
	char	p_al;
	
	if (!map || !piece)
		return ;
	map_root = ft_strlen(map[0]);
	p_x = ft_strlen(piece[0]);
	p_y = piece_y(piece);
	if ((p = (int*)(malloc(sizeof(int) * 2))))
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
	free(p);
	return ;
}
