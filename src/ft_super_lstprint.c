/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_lstprint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 23:21:17 by bmiller           #+#    #+#             */
/*   Updated: 2017/01/06 23:23:20 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_super_lstprint(t_list *lst, void (*f)(char**))
{
	if (!lst)
		return ;
	f(lst->content);
	ft_putstr("\n");
	if (!(lst->next))
	{
		ft_putchar('\n');
		return ;
	}
	return (ft_super_lstprint(lst->next, f));
}
