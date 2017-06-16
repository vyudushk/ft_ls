/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:02:54 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/15 17:45:04 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

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

int		is_time_sort(t_flag *flags, t_list *work)
{
	t_list		*lst;
	struct stat	info;
	struct stat	inext;

	lst = work;
	while (lst->next->content)
	{
		stat(lst->content, &info);
		stat(lst->next->content, &inext);
		if ((!flags->r && (info.st_mtime < inext.st_mtime))
			|| (flags->r && (info.st_mtime > inext.st_mtime)))
			return (0);
		lst = lst->next;
	}
	return (1);
}

char	*uidget(struct stat info)
{
	struct passwd	*pwd;

	pwd = getpwuid(info.st_uid);
	return (pwd->pw_name);
}

void	shorten(t_flag *flags, t_list *hold, t_list *next, char *name)
{
	if (lst_len(hold))
		print_list(flags, hold, name);
	ft_lstdel(&hold, del);
	if (flags->ur && lst_len(next))
		process(flags, next);
	ft_lstdel(&next, del);
}
