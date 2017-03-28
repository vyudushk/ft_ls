/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:55:07 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/07 17:05:51 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*res;

	res = dst;
	while (*src && len)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len)
	{
		*dst = 0;
		dst++;
		len--;
	}
	return (res);
}
