/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:20:18 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 17:48:56 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

int					fits(char **piece, char **map, size_t x, size_t y)
{
	size_t		map_root;
	size_t		p_x;
	size_t		p_y;
	size_t		*p;

	if (!map || !piece)
		return (-1);
	map_root = (size_t)ft_strlen(map[0]);
	p_x = (size_t)ft_strlen(piece[0]);
	p_y = piece_y(piece);
	if ((p = (size_t*)(malloc(sizeof(size_t) * 2))))
	{
		p[0] = x;
		p[1] = y;
	}
	else
		return (-1);
	while (p[1] <= (map_root - p_y))
	{
		while (p[0] <= (map_root - p_x))
		{
			if (map[p[1]][p[0]] == '.' || piece[0][0] == '.')
				if (fitter(piece, map, p[0], p[1]))
				{
					ft_memdel((void**)&p);
					return (1);
				}
			p[0]++;
		}
		p[0] = 0;
		p[1]++;
	}
	ft_memdel((void**)&p);
	return (0);
}
