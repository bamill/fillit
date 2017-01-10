/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stomultistr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:14:11 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/09 21:59:41 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

t_list	*ft_stomultistr(t_list *lst)
{
	lst->content = ft_strsplit(lst->content, '\n');
	lst->content_size = \
		(ft_strlen(((char**)lst->content)[0]) + 1) * piece_y(lst->content);
	return (lst);
}
