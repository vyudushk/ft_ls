/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:02:54 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/09 21:15:31 by vyudushk         ###   ########.fr       */
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
		while(lst->next->content)
		{
			if ((!flags->r && ft_strcmp(lst->content, lst->next->content) > 0) ||
				(flags->r && ft_strcmp(lst->content, lst->next->content) < 0))
			{
				hold = lst->content;
				lst->content = lst->next->content;
				lst->next->content = hold;
			}
			lst = lst->next;
		}
	}
}

void	print_list(t_flag *flags, t_list *work)
{
	sort_lst(flags, &work);
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
