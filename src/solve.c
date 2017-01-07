/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:20:40 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 21:01:57 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		solve(t_list *pieces, char **map, size_t sq)
{
	size_t	i;

	if (!pieces || !pieces->content)
		return (1);
	i = ft_lstlen(pieces);
	while (i > 0)
	{
		if (fits(pieces->content, map))
		{
			place(pieces->content, map);
			if (solve(pieces->next, map, sq))
				return (1);
			unplace(pieces->content, map);
		}
		i--;
		pieces = ft_lst_rot(pieces, 1);
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
				ft_memset(map[i], '.', sq);
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
	while (!solve(piecey, map, sq))
	{
		sq++;
		map = create_map(map, sq);
	}
	ft_lstdel(&piecey, &ft_bzero);
//	ft_lstdel(pieces, &ft_bzero);
	return (map);
}
