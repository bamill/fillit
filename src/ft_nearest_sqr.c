/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nearest_sqr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:53:17 by azimina           #+#    #+#             */
/*   Updated: 2017/01/03 15:53:44 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nearest_sqr(int nb)
{
	int root;

	root = 0;
	while ((root * root) < nb)
		root++;
	return (root);
}
