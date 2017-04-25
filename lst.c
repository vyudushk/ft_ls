/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:47:57 by vyudushk          #+#    #+#             */
/*   Updated: 2017/04/24 22:00:58 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libls.h"
#include <unistd.h>
#include <dirent.h>

/*
** I'm just keeping here so that I remember what I learned
** from kdavis.
**
** TODO: Make a macro to make derefrencing the string much
** easier to read.
**
**	struct dirent	hold;
**
**	hold = *((struct dirent*)(lst->content));
**	ft_putendl(hold.d_name);
*/

void		print_lst_dot(t_list *lst)
{
	ft_putendl(((struct dirent*)(lst->content))->d_name);
}

void		print_lst(t_list *lst)
{
	if (((struct dirent*)(lst->content))->d_name[0] != '.')
		ft_putendl(((struct dirent*)(lst->content))->d_name);
}

void		process_lst(t_list *lst, t_flag *options)
{
	sort_lst(&lst, options);
	if (options->include_dot)
		ft_lstiter(lst, print_lst_dot);
	else
		ft_lstiter(lst, print_lst);
}

static int	is_lst_sort(t_list *lst, t_flag *opt)
{
	while (lst->next)
	{
		if ((!opt->rev && ft_strcmp(((struct dirent*)(lst->content))->d_name,
				((struct dirent*)(lst->next->content))->d_name) > 0) ||
			(opt->rev && ft_strcmp(((struct dirent*)(lst->content))->d_name,
				((struct dirent*)(lst->next->content))->d_name) < 0))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void		sort_lst(t_list **input, t_flag *opt)
{
	t_list	*lst;
	t_list	*head;
	void	*hold;

	lst = *input;
	head = lst;
	while (is_lst_sort(head, opt) == 0)
	{
		lst = head;
		while (lst->next)
		{
			if ((!opt->rev && (ft_strcmp(((struct dirent*)(lst->content))->d_name,
					((struct dirent*)(lst->next->content))->d_name) > 0)) ||
				(opt->rev && (ft_strcmp(((struct dirent*)(lst->content))->d_name,
					((struct dirent*)(lst->next->content))->d_name) < 0)))
			{
				hold = lst->content;
				lst->content = lst->next->content;
				lst->next->content = hold;
			}
			lst = lst->next;
		}
	}
}
