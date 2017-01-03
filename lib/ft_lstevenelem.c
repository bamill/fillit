/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstevenelem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 22:44:29 by azimina           #+#    #+#             */
/*   Updated: 2016/12/29 23:34:09 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstevenelem(t_list **lst)
{
	t_list	*current;
	t_list	*new;
	t_list	*next;

	current = *lst;
	if ((current != NULL) && (new = ft_lstnew(current->content, 
					current->content_size)))
	{
		current = current->next->next;
		while (current != NULL)
		{
			ft_lstpush_back(&new, current->content, current->content_size);
			current = current->next->next;
		}
		ft_lsttotaldel(lst);
		return (new);
	}
	return (NULL);
}
