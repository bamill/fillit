/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:17:34 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 20:01:18 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	print_map(char **map)
{
	int	i;
	int j;

	j = piece_y(map);
	i = 0;
	while (i < j)
	{
		ft_putstr(*(map + i));
		ft_putstr("\n");
		i++;
	}
	return ;
}
