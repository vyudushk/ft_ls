/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:43:49 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/13 16:29:02 by vyudushk         ###   ########.fr       */
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

int		is_nano_sort(t_flag *flags, t_list *work)
{
	t_list		*lst;
	struct stat	info;
	struct stat	inext;

	lst = work;
	while (lst->next->content)
	{
		stat(lst->content, &info);
		stat(lst->next->content, &inext);
		if ((!flags->r &&
			(info.st_mtimespec.tv_nsec < inext.st_mtimespec.tv_nsec))
			|| (flags->r &&
			(info.st_mtimespec.tv_nsec > inext.st_mtimespec.tv_nsec)))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_lst_nano(t_flag *flags, t_list **work)
{
	t_list		*lst;
	t_list		*head;
	void		*hold;
	struct stat	info;
	struct stat	inext;

	lst = *work;
	head = lst;
	while (is_nano_sort(flags, head) == 0)
	{
		lst = head;
		while (lst->next->content)
		{
			stat(lst->content, &info);
			stat(lst->next->content, &inext);
			if (((!flags->r && (GET_NANOSEC(info) < GET_NANOSEC(inext))))
				|| (flags->r && (GET_NANOSEC(info) > GET_NANOSEC(inext))))
			{
				hold = lst->content;
				lst->content = lst->next->content;
				lst->next->content = hold;
			}
			lst = lst->next;
		}
	}
}

void	sort_lst_time(t_flag *flags, t_list **work)
{
	t_list		*lst;
	t_list		*head;
	void		*hold;
	struct stat	info;
	struct stat	inext;

	lst = *work;
	head = lst;
	while (is_time_sort(flags, head) == 0)
	{
		lst = head;
		while (lst->next->content)
		{
			stat(lst->content, &info);
			stat(lst->next->content, &inext);
			if ((!flags->r && (info.st_mtime < inext.st_mtime))
				|| (flags->r && (info.st_mtime > inext.st_mtime)))
			{
				hold = lst->content;
				lst->content = lst->next->content;
				lst->next->content = hold;
			}
			lst = lst->next;
		}
	}
}

void	sort_lst_normal(t_flag *flags, t_list **work)
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

void	sort_lst(t_flag *flags, t_list **work)
{
	if (flags->t == 0)
		sort_lst_normal(flags, work);
	if (flags->t == 1)
	{
		sort_lst_nano(flags, work);
		sort_lst_time(flags, work);
	}
}
