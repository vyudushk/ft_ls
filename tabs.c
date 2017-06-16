/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:39:13 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/15 17:35:41 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		get_name_tab(t_list *work, char *name)
{
	size_t			longest;
	struct stat		info;
	struct passwd	*pwd;

	longest = 0;
	while (work->next->content)
	{
		stat(ft_strjoin(name, work->content), &info);
		pwd = getpwuid(info.st_uid);
		if (ft_strlen(pwd->pw_name) > longest)
		{
			longest = ft_strlen(pwd->pw_name);
		}
		work = work->next;
	}
	return (longest);
}

int		get_link_tab(t_list *work, char *name)
{
	size_t		longest;
	struct stat	info;

	longest = 0;
	while (work->next->content)
	{
		stat(ft_strjoin(name, work->content), &info);
		if (ft_strlen(ft_itoa(info.st_nlink)) > longest)
			longest = ft_strlen(ft_itoa(info.st_nlink));
		work = work->next;
	}
	return (longest);
}

int		get_tab(t_list *work, char *name)
{
	size_t		longest;
	struct stat	info;

	longest = 0;
	while (work->next->content)
	{
		stat(ft_strjoin(name, work->content), &info);
		if (ft_strlen(ft_itoa(info.st_size)) > longest)
			longest = ft_strlen(ft_itoa(info.st_size));
		work = work->next;
	}
	return (longest);
}

int		get_group_tab(t_list *work, char *name)
{
	size_t			longest;
	struct stat		info;
	struct group	*grp;

	longest = 0;
	while (work->next->content)
	{
		stat(ft_strjoin(name, work->content), &info);
		grp = getgrgid(info.st_gid);
		if (ft_strlen(grp->gr_name) > longest)
		{
			longest = ft_strlen(grp->gr_name);
		}
		work = work->next;
	}
	return (longest);
}

void	ft_printtab(int tab, char *str, int mode)
{
	tab = tab - ft_strlen(str);
	if (mode == 1)
		ft_putstr(str);
	while (tab--)
	{
		ft_putchar(' ');
		if (tab < 0)
			break ;
	}
	if (mode == 0)
		ft_putstr(str);
	ft_putchar(' ');
}
