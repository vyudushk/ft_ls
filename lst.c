/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:47:57 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/31 21:03:39 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void		print_lst(t_list *lst)
{
	ft_putendl(lst->content);

/*
**	char	*test;
**
**	test = (char*)lst->content;
**	if (test[0] != '.')
**		ft_putendl(lst->content);
*/
}

static int	is_lst_sort(t_list *lst)
{
	while (lst->next)
	{
		if (ft_strcmp(lst->content, lst->next->content) > 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void		sort_lst(t_list **input)
{
	t_list	*lst;
	t_list	*head;
	void	*hold;

	lst = *input;
	head = lst;
	while (is_lst_sort(head) == 0)
	{
		lst = head;
		while (lst->next)
		{
			if (ft_strcmp(lst->content, lst->next->content) > 0)
			{
				hold = lst->content;
				lst->content = lst->next->content;
				lst->next->content = hold;
			}
			lst = lst->next;
		}
	}
}

