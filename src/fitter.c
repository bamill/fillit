/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 23:29:00 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 23:29:19 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			fitter(char **piece, char **map, size_t *p)
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
				&& map[(p[1] + p_y) - 1][(p[0] + p_x) - 1] != '.')
				return (0);
			p_x--;
		}
		p_x = (size_t)ft_strlen(piece[0]);
		p_y--;
	}
	return (1);
}
