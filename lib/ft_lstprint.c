/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:46:11 by azimina           #+#    #+#             */
/*   Updated: 2016/12/29 18:06:58 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (lst == NULL)
		ft_putstr("error_reading\n");
	while (current != NULL)
	{
		ft_putstr((char *)current->content);
		current = current->next;
	}
}
