/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:03:21 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 18:49:52 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

static int			fitters(char **piece, char **map, size_t x, size_t y)
{
	size_t		p_x;
	size_t		p_y;

	p_x = (size_t)ft_strlen(piece[0]);
	p_y = piece_y(piece);
	while (p_y > 0)
	{
		while (p_x > 0)
		{
			if (piece[p_y - 1][p_x - 1] != '.'\
				&& map[(y + p_y) - 1][(x + p_x) - 1] != '.')
				return (0);
			p_x--;
		}
		p_x = (size_t)ft_strlen(piece[0]);
		p_y--;
	}
	return (1);
}

static void		placement(char **piece, char **map, size_t x, size_t y)
{
	size_t	p_x;
	size_t	p_y;

	p_x = (size_t)ft_strlen(piece[0]);
	p_y = piece_y(piece);
	while (p_y > 0)
	{
		while (p_x > 0)
		{
			if (piece[p_y - 1][p_x - 1] != '.')
				map[(y + p_y) - 1][(x + p_x) - 1] = piece[p_y - 1][p_x - 1];
			p_x--;
		}
		p_x = (size_t)ft_strlen(piece[0]);
		p_y--;
	}
	return ;
}

void			place(char **piece, char **map, size_t x, size_t y)
{
	size_t	map_root;
	size_t	p_x;
	size_t	p_y;

	if (!map || !piece)
		return ;
	map_root = (size_t)ft_strlen(map[0]);
	p_x = (size_t)ft_strlen(piece[0]);
	p_y = piece_y(piece);
	while (y <= (map_root - p_y))
	{
		while (x <= (map_root - p_x))
		{
			if (map[y][x] == '.' || piece[0][0] == '.')
				if (fitters(piece, map, x, y))
				{
					placement(piece, map, x, y);
					return ;
				}
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}
