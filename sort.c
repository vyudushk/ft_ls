/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:43:49 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/12 23:03:28 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		is_sort(t_flag *flags, t_list *work)
{
	t_list	*lst;

	lst = work;
	while (lst->next->content)
	{
		if ((!flags->r && ft_strcmp(lst->content, lst->next->content) > 0) ||
			(flags->r && ft_strcmp(lst->content, lst->next->content) < 0))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_lst(t_flag *flags, t_list **work)
{
	t_list	*lst;
	t_list	*head;
	void	*hold;

	lst = *work;
	head = lst;
	while (is_sort(flags, head) == 0)
	{
		lst = head;
		while (lst->next->content)
		{
			if ((!flags->r && ft_strcmp(lst->content, lst->next->content) > 0)
			|| (flags->r && ft_strcmp(lst->content, lst->next->content) < 0))
			{
				hold = lst->content;
				lst->content = lst->next->content;
				lst->next->content = hold;
			}
			lst = lst->next;
		}
	}
}
