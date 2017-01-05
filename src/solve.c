/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:20:40 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/04 16:26:58 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	solve(t_list *pieces, char **map, size_t sq)
{
	size_t	i;
	t_list	**pieces_p;

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

char		**solver(t_list **pieces)
{
	t_list	*pieces_p;
	int		tetrominoses;
	int		sq;
	char	**map;

	pieces_p = *pieces;
	tetrominoses = ft_lstlen(pieces_p);
	sq = ft_nearest_sqr(tetrominoses * 4);
	map = create_map(NULL, sq);
	while (!solve(pieces_p, map, sq, 0))
	{
		sq++;
		map = create_map(map, sq);
	}
	ft_lstdel(pieces_p, &ft_bzero);
	return (map);
}

char		**create_map(char **oldmap, int sq)
{
	int		i;
	char	**map;

	i = 0;
	length = width * (1 + width);
	if (oldmap != NULL)
		ft_memdel(oldmap);
	if ((map = (char**)malloc(sizeof(char*) * sq + 1)))
	{
		while (i < sq)
		{
			if ((map[i] = (char*)malloc(sq + 1)))
				ft_memset(map[i], '.', sq);
			i++;
			else
				return (NULL);
		}
		return (map);
	}
	return (NULL);
}
