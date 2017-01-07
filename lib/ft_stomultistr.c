/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stomultistr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:14:11 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 20:14:26 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>

t_list	*ft_stomultistr(t_list *lst)
{
	lst->content = ft_strsplit(lst->content, '\n');
	lst->content_size = sizeof(lst->content);
	return (lst);
}
