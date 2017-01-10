/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:17:48 by azimina           #+#    #+#             */
/*   Updated: 2017/01/09 20:45:58 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

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

int			main(int ac, char **av)
{
	int		fd;
	t_list	*lst;
	char	**map;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)))
		{
			lst = ft_read(fd);
			if (lst == NULL)
			{
				ft_putstr("error\n");
				return (0);
			}
			map = solver(&lst);
			print_map(map);
		}
		if (close(fd) == -1)
			return (0);
	}
	else if (ac == 1)
		ft_putstr("Usage: ./fillit source_file\n");
	else
		ft_putstr("error\n");
	return (0);
}
