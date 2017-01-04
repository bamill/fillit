/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bisquick_mkii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:57:48 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/03 15:01:46 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			**bisquick(char *in_str, size_t x_dim, size_t y_dim)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char**)(malloc(sizeof(char*) * y_dim + 1));
	while (i <= (int)y_dim)
	{
		arr[i] = (char*)(malloc((x_dim + 1)));
		i++;
	}
	bisquick_pop(&arr, in_str);
	return (arr);
}

static void		bisquick_pop(char ***arr, char *in_str)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (*(in_str + i))
	{
		if (in_str[i] == '\n')
		{
			(*arr)[y][x] = '\0';
			y++;
			x = 0;
		}
		else
		{
			(*arr)[y][x] = in_str[i];
			x++;
		}
		i++;
	}
}
