/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unplace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:18:58 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 19:59:56 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static char	piece_char(char **piece)
{
	size_t	i;

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

void		unplace(char **piece, char **map)
{
	int		i;
	int		j;
	int		map_root;
	char	p_al;

	if (!map || !piece)
		return ;
	i = 0;
	j = 0;
	map_root = ft_strlen(map[0]);
	p_al = piece_char(piece);
	while (j < map_root)
	{
		while (i < map_root)
		{
			map[j][i] = map[j][i] == p_al ? '.' : map[j][i];
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}
