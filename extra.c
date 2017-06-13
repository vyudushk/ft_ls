/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:02:54 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/12 16:28:53 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

t_list	*rev_list(t_list *input)
{
	t_list	*res;

	ft_lstnew(NULL, 0);
	while (input->next->content)
	{
		ft_lstadd(&res, ft_lstnew(input->content, input->content_size));
		input = input->next;
	}
	return (res);
}

void	print_list(t_flag *flags, t_list *work)
{
	while (work->next)
	{
		if (flags)
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
