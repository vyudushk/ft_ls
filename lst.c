/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:47:57 by vyudushk          #+#    #+#             */
/*   Updated: 2017/04/11 19:13:15 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libls.h"

void		print_lst_dot(t_list *lst)
{
	ft_putendl(lst->content);
}

void		print_lst(t_list *lst)
{
	char	*str;

	str = lst->content;
	if (str[0] != '.')
		ft_putendl(lst->content);
}

void		process_lst(t_list *lst, t_flag *options)
{
	if (options->include_dot)
		ft_lstiter(lst, print_lst_dot);
	else
		ft_lstiter(lst, print_lst);
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
