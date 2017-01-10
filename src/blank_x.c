/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blank_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 22:09:10 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 22:45:59 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		blank_x(int j, int x, int num_blanks, char ***piece)
{
	int	i;

	i = 0;
	if (num_blanks == x)
	{
		while (i < x)
		{
			(*piece)[j][i] = ' ';
			i++;
		}
		return (1);
	}
	return (0);
}

int		blank_y(int i, int y, int num_blanks, char ***piece)
{
	int j;

	j = 0;
	if (num_blanks == y)
	{
		while (j < y)
		{
			(*piece)[j][i] = ' ';
			j++;
		}
		return (1);
	}
	return (0);
}
