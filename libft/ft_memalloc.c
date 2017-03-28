/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:03:08 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/17 16:44:49 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	res = (void*)malloc(size);
	if (res == 0)
		return (0);
	else
	{
		ft_bzero(res, size);
		return (res);
	}
}
