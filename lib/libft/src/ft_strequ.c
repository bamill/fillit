/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:12:36 by bmiller           #+#    #+#             */
/*   Updated: 2016/12/03 02:34:16 by bmiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (1);
	if (*s1 == *s2 && *s1)
		return (ft_strequ(s1 + 1, s2 + 1));
	if (*s1 != *s2)
		return (0);
	return (1);
}
