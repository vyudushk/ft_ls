/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:47:57 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/06 21:00:43 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libls.h"
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

/*
** I'm just keeping here so that I remember what I learned
** from kdavis.
**
**	struct dirent	hold;
**
**	hold = *((struct dirent*)(lst->content));
**	ft_putendl(hold.d_name);
**
**  the GET_NAME(lst) macro now just pulls out the name from the lst as a
**  regular indexable array
*/

void		print_lst_dot(t_list *lst)
{
	ft_putendl(lst->content);
}

void		print_lst(t_list *lst)
{
	char	*hold;

	hold = (char*)(lst->content);
	if (hold && hold[0] != '.')
		ft_putendl(lst->content);
}

void		process_lst(t_flag *work)
{
	sort_lst(work);
	if (work->include_dot)
		ft_lstiter(work->dirs, print_lst_dot);
	else
		ft_lstiter(work->dirs, print_lst);
}

static int	is_lst_sort(t_flag *work)
{
	t_list *lst;

	lst = work->dirs;
	while (lst->next)
	{
		if ((!work->rev && 
					ft_sstrcmp((char*)(lst->content), 
						(char*)(lst->next->content)) > 0) ||
			(work->rev && ft_sstrcmp((char*)(lst->content), (char*)(lst->next->content)) < 0))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void		sort_lst(t_flag *work)
{
	t_list	*lst;
	t_list	*head;
	void	*hold;

	lst = work->dirs;
	head = work->dirs;
	while (is_lst_sort(work) == 0)
	{
		lst = head;
		while (lst->next->content)
		{
			if ((!work->rev &&
						(ft_sstrcmp((char*)(lst->content), (char*)(lst->next->content)) > 0))
				|| (work->rev &&
						(ft_sstrcmp((char*)(lst->content), (char*)(lst->next->content)) < 0)))
			{
				hold = lst->content;
				lst->content = lst->next->content;
				lst->next->content = hold;
			}
			lst = lst->next;
		}
	}
}
