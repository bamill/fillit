/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:45:51 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 14:49:39 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lst_strsplit(t_list *lst)
{
	lst->content = ft_strsplit(lst->content, '\n');
	lst->content_size = sizeof(lst->content);
	return (lst);
}
