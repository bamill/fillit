/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:20:40 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 22:04:10 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		solve(t_list *pieces, char **map, int x, int y)
{
	int		max_x;
	int		max_y;

	if (!pieces || !pieces->content)
		return (1);
	max_x = ft_strlen(map[0]) - ft_strlen(((char**)pieces->content)[0]);
	max_y = (int)ft_strlen(map[0]) - piece_y(pieces->content);
	if ((int)piece_y(pieces->content) <= (int)ft_strlen(map[0]))
		while (y <= max_y)
		{
			while (x <= max_x)
			{
				if (fitter(pieces->content, map, x, y))
				{
					place(pieces->content, map, x, y);
					if (solve(pieces->next, map, 0, 0))
						return (1);
					unplace(pieces->content, map);
				}
				x++;
			}
			x = 0;
			y++;
		}
	return (0);
}

static char		**create_map(char **oldmap, int sq)
{
	int		i;
	char	**map;

	i = 0;
	if (oldmap != NULL)
		ft_memdel((void**)oldmap);
	if ((map = (char**)malloc(sizeof(char*) * sq + 1)))
	{
		while (i < sq)
		{
			if ((map[i] = (char*)malloc(sq + 1)))
			{
				ft_memset(map[i], '.', sq);
				map[i][sq] = 0;
			}
			else
				return (NULL);
			i++;
		}
		return (map);
	}
	return (NULL);
}

char			**solver(t_list **pieces)
{
	t_list	*piecey;
	int		tetrominoses;
	int		sq;
	char	**map;

	piecey = *pieces;
	tetrominoses = ft_lstlen(piecey);
	sq = ft_nearest_sqr(tetrominoses * 4);
	alphabeterizer(piecey, tetrominoses, 0);
	piecey = ft_lstmap(ft_lstmap(piecey, &ft_stomultistr), &piece_trim_lst);
	map = create_map(NULL, sq);
	while (!solve(piecey, map, 0, 0))
	{
		sq++;
		map = create_map(map, sq);
	}
	ft_lstdel(&piecey, &ft_bzero);
	return (map);
}
