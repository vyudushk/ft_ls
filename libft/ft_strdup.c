/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:01:10 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/18 16:56:33 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(s1);
	i = 0;
	res = (char*)malloc(sizeof(char) * len + 1);
	if (res == 0)
		return (0);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
