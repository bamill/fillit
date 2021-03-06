/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:02:00 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 15:03:03 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
** Counting connections between #. Should be 8 for square and 6 for all others.
*/

static int		con_num(char *str, int i, char c, int width)
{
	int con;
	int maxlen;

	con = 0;
	maxlen = width * (1 + width);
	if ((i < (maxlen - 1)) && (str[i + 1] == c))
		con++;
	if ((i > 0) && (str[i - 1] == c))
		con++;
	if ((i < (maxlen - 1 - (width + 1))) && (str[i + (width + 1)] == c))
		con++;
	if ((i > width) && (str[i - (width + 1)] == c))
		con++;
	return (con);
}

static int		is_at_other_spot(char *str, int i, char c, int width)
{
	int maxlen;

	maxlen = width * (1 + width);
	if ((i < (maxlen - 1)) && (str[i + 1] == c))
		return (1);
	if ((i > 0) && (str[i - 1] == c))
		return (1);
	if ((i < (maxlen - 1 - (width + 1))) && (str[i + (width + 1)] == c))
		return (1);
	if ((i > width) && (str[i - (width + 1)] == c))
		return (1);
	return (0);
}

/*
** Checking the number of # for being the valid Tetriminos (4) and if every #
** has at least 1 proper connection.
*/

static int		check_stars(char *str)
{
	int star;
	int i;
	int con;

	star = 0;
	i = 0;
	con = 0;
	while (i < SIZE)
	{
		if (str[i] == '#')
		{
			if (is_at_other_spot(str, i, '#', 4))
			{
				con = con_num(str, i, '#', 4) + con;
				star++;
			}
			else
				return (0);
		}
		i++;
	}
	if ((star == 4) && (con >= 6))
		return (1);
	return (0);
}

/*
** Checking number on new lines in the Tetriminos (4)
*/

static int		check_nl(char *str)
{
	int n_l;
	int i;

	n_l = 0;
	i = 0;
	while (i < SIZE)
	{
		if (str[i] == '\n')
		{
			if (!((i + 1) % 5))
				n_l++;
			else
				return (0);
		}
		i++;
	}
	if (n_l == 4)
		return (1);
	return (0);
}

/*
** Verifing the read block - if it is the proper Tetriminos: 4 #, 4 newlines.
*/

int				verif(char *str)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		if ((str[i] == '#') || (str[i] == '.') || (str[i] == '\n'))
			i++;
		else
			return (0);
	}
	if ((str[i] != '\n') && ft_isascii(str[i]))
		if ((str[i] != '\0') && ft_isascii(str[i]))
			return (0);
	if (check_stars(str) && check_nl(str))
		return (1);
	return (0);
}
