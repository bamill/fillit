/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:28:28 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/07 00:54:26 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int				trim_mark_rows(char ***piece, int x, int y, char c)
{
	int		i;
	int		j;
	int		blank_rows;
	int		num_blanks;

	i = 0;
	j = 0;
	num_blanks = 0;
	blank_rows = 0;
	while (j < y)
	{
		while (i < x)
		{
			if ((*piece)[j][i] == c)
				num_blanks++;
			i++;
		}
		i = 0;
		if (num_blanks == x)
		{
			while (i < x)
			{
				(*piece)[j][i] = ' ';
				i++;
			}
			blank_rows++;
		}
		num_blanks = 0;
		i = 0;
		j++;
	}
	return (blank_rows);
}

static int				trim_mark_cols(char ***piece, int x, int y, char c)
{
	int		i;
	int		j;
	int		blank_cols;
	int		num_blanks;

	i = 0;
	j = 0;
	num_blanks = 0;
	blank_cols = 0;
	while (i < x)
	{
		while (j < y)
		{
			if ((*piece)[j][i] == c || (*piece)[j][i] == ' ')
				num_blanks++;
			j++;
		}
		j = 0;
		if (num_blanks == y)
		{
			while (j < y)
			{
				(*piece)[j][i] = ' ';
				j++;
			}
			blank_cols++;
		}
		num_blanks = 0;
		j = 0;
		i++;
	}
	return (blank_cols);
}

static char				**trim(char ***piece, int x, int y)
{
	char	**result;
	int		i;
	int		j;

	result = (char**)(malloc(sizeof(char*) * y + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < y)
	{
		while (ft_strlen(ft_strtrim((*piece)[j])) == 0)
			j++;
		result[i] = (char*)(malloc(x + 1));
		ft_memcpy(result[i], ft_strtrim((*piece)[j]), x + 1);
		i++;
		j++;
	}
	result[i] = NULL;
	return (result);
}

static char				**piece_trim(char **piece)
{
	char	***this_piece;
	char	**result;
	int		x;
	int		y;

	x = 4;
	y = 4;
	this_piece = (char***)(malloc(sizeof(char**)));
	*this_piece = piece;
	y -= trim_mark_rows(this_piece, 4, 4, '.');
	x -= trim_mark_cols(this_piece, 4, 4, '.');
	result = trim(this_piece, x, y);
	ft_memdel((void*)(*this_piece));
	return (result);
}

t_list					*piece_trim_lst(t_list *lst)
{
	if (!lst)
		return (NULL);
	lst->content = piece_trim(lst->content);
	lst->content_size = sizeof(lst->content);
	return (lst);
}
