/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:17:48 by azimina           #+#    #+#             */
/*   Updated: 2017/01/03 16:08:03 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

/*
** Counting connections between #. Should be 8 for square and 6 for all others.
*/

int		con_num(char *str, int i, char c, int width)
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

int		is_at_other_spot(char *str, int i, char c, int width)
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

int		check_stars(char *str)
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

int		check_nl(char *str)
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

int		verif(char *str)
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

/*
** Reading the input (21 symbols at a time). If read and 20 symbols are good
** Tetrimonos, storing it in 1st elem of the list, storing 21st elem in 2nd
** element of the list and so on. The last elem in the list should always be
** empty.
*/

t_list		*ft_read(int fd)
{
	int		ret;
	t_list	*new;
	char	buf[SIZE + 1];
	char	separ[1];

	new = NULL;
	while ((ret = read(fd, buf, SIZE + 1)))
	{
		if (verif(buf))
		{
			separ[0] = buf[SIZE];
			buf[SIZE] = '\0';
			ft_lstpush_back(&new, buf, SIZE + 1);
			ft_lstpush_back(&new, separ, 1);
			ft_memset(buf, 0, SIZE + 1);
		}
		else
			return (NULL);
	}
	if ((new != NULL) && (((((char *)ft_lstlastelem(new))[0]) == '\n')
				|| (ft_lstlen(new) > 52)))
		return (NULL);
	else
		return (ft_lstevenelem(&new));
}

int		main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)))
		{
			ft_lstprint(ft_read(fd));
		}
	}
	else if (ac == 1)
		ft_putstr("usage ...");
	else
		ft_putstr("error\n");
	return (0);
}
