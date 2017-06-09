/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:02:54 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/09 10:11:02 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	print_list(t_list *work)
{
	while (work->next)
	{
		ft_putendl(work->content);
		work = work->next;
	}
}

int		lst_len(t_list *head)
{
	int	i;

	i = 0;
	while (head->next)
	{
		i++;
		head = head->next;
	}
	return (i);
}
