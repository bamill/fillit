/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabeterizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:19:55 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/03 17:28:24 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	alphabeterizer(t_list *pieces, size_t s, size_t n)
{
	int i;

	i = 0;
	if (!pieces || !(pieces->content) || s == 0)
		return ;
	while (((char *)pieces->content)[i])
	{
		if (((char *)pieces->content)[i] == '#')
		((char*)pieces->content)[i] = ('A' + n);
		i++;
	}
	alphabeterizer(pieces->next, s - 1, n + 1);
}
