/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:20:18 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 21:36:36 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static int		fitter(char **piece, char **map, int *p)
{
	int		p_x;
	int		p_y;

	p_x = ft_strlen(piece[0]);
	p_y = piece_y(piece);
	while (p_y > 0)
	{
		while (p_x > 0)
		{
			if (piece[p_y - 1][p_x - 1] != '.'\
				&& map[(p[1] + p_y) - 1][(p[0] + p_x) - 1] != '.')
				return (0);
			p_x--;
		}
		p_x = ft_strlen(piece[0]);
		p_y--;
	}
	return (1);
}

int				fits(char **piece, char **map)
{
	int		map_root;
	int		p_x;
	int		p_y;
	int		*p;

	if (!map || !piece)
		return (-1);
	map_root = ft_strlen(map[0]);
	p_x = ft_strlen(piece[0]);
	p_y = piece_y(piece);
	if ((p = (int*)(malloc(sizeof(int) * 2))))
	{
		p[0] = 0;
		p[1] = 0;
	}
	else
		return (-1);
	while (p[1] <= (map_root - p_y))
	{
		while (p[0] <= (map_root - p_x))
		{
			if (map[p[1]][p[0]] == '.' || piece[0][0] == '.')
				if (fitter(piece, map, p))
				{
					free(p);
					return (1);
				}
			p[0]++;
		}
		p[0] = 0;
		p[1]++;
	}
	free(p);
	return (0);
}
