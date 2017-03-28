/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:36:51 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/01 14:07:34 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char		find;
	const char	*start;

	find = (char)c;
	start = s;
	while (*s != 0)
		s++;
	if (*s == find)
		return ((char*)s);
	while (s != start)
	{
		if (*s == find)
			return ((char *)s);
		s--;
	}
	if (*s == find)
		return ((char *)s);
	return (0);
}
