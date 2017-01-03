/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabeterizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:19:55 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/02 17:27:50 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	alphabeterizer(t_list *pieces, size_t s, size_t n)
{
	int i;

	i = 0;
	if (!pieces || !(pieces->content) || size == 0)
		return ;
	while (pieces->content[i])
	{
		if (pieces->content[i] == '#')
		pieces->content[i] = ('A' + n);
		i++;
	}
	alphabeterizer(pieces->next, s - 1, n + 1);
}
