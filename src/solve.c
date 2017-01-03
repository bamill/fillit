/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:20:40 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/02 20:30:52 by bmiller          ###   ########.fr       */
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

t_list		*solver(t_list *pieces, t_list *map, size_t sq)
{
	t_list	**pieces_p;

	*pieces_p = pieces;
	while (!solve(pieces, map, sq, 0))
	{
		level_map(map, sq);
		sq++;
	}
	ft_lstdel(pieces_p, &ft_bzero);
	return (map);
}
