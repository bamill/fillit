/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:20:18 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/04 22:24:08 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static int		fitter(char **piece, char **map_point, size_t p_x, size_t p_y)
{
	while (p_y > 0)
	{
		while (p_x > 0)
		{
			if (piece[p_y - 1][p_x - 1] != '.'\
				 && map_point[p_y - 1][p_x - 1] != '.')
				return (0);
			p_x--;
		}
		p_y--;
	}
	return (1);
}

int				fits(char **piece, char **map)
{
	size_t	map_root;
	size_t	p_x;
	size_t	p_y;
	size_t	*p;

	if (!map || !piece)
		return (-1);
	map_root = sizeof(map[0]) - 1;
	p_x = sizeof(piece[0]) - 1;
	p_y = sizeof(piece) - 1;
	if (p = (size_t*)(malloc(sizeof(size_t) * 2)))
	{
		p[0] = 0;
		p[1] = 0;
	}
	else
		return (-1);
	while (p[1] < (map_root - p_y))
	{
		while (p[0] < (map_root - p_x))
		{
			if (map[p[1]][p[0]] == '.' || piece[0][0] == '.')
				if (fitter(piece, map[p[1]][p[0]], p_x, p_y))
				{
					free(p);
					return (1);
				}
			p[0]++;
		}
		p[1]++;
	}
	free(p);
	return (0);
}
