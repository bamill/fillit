/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:20:40 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/03 17:03:19 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	solve(t_list *pieces, t_list *map, size_t sq)
{
	size_t	i;
	t_list	**pieces_p;

	if (!pieces || !pieces->content)
		return (1);
	i = ft_lstlen(pieces);
	while (i > 0)
	{
		if (fits(pieces->content, map, sq))
		{
			place(pieces->content, map, sq);
			if (solve(pieces->next, map, sq))
				return (1);
			unplace(pieces->content, map, sq);
		}
		i--;
		pieces = ft_lst_rot(pieces, 1);
	}
	return (0);
}

char		*solver(t_list **pieces)
{
	t_list	*pieces_p;
	int		tetrominoses;
	int		sq;
	char	*map;

	pieces_p = *pieces;
	tetrominoses = ft_lstlen(pieces_p);
	sq = ft_nearest_sqr(tetrominoses * 4);
	map = create_map(NULL, sq);
	while (!solve(pieces_p, map, sq, 0))
	{
		map = create_map(map, sq);
		sq++;
	}
	ft_lstdel(pieces_p, &ft_bzero);
	return (map);
}

char		*create_map(char *oldmap, int width)
{
	int		i;
	int		length;
	char	*map;
	char	firstrow[width + 2];

	i = 0;
	length = width * (1 + width);
	if (oldmap != NULL)
	{
		free(oldmap);
		oldmap = NULL;
	}
	if ((map = (char *)malloc(sizeof(char) * (length + 1))))
	{
		ft_memset(firstrow, '.', width);
		firstrow[width] = '\n';
		firstrow[width + 1] = '\0';
		while (i < width)
		{
			ft_strcat(map, firstrow);
			i++;
		}
		return (map);
	}
	return (NULL);
}
