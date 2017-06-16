/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:42:27 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/15 17:43:24 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		permission(struct stat info)
{
	if (GET_RUS(info) || (!S_IRGRP & info.st_mode &&
				!ft_strcmp(uidget(info), "root")))
	{
		ft_putstr_fd(" Permission denied\n", 2);
		return (1);
	}
	return (0);
}

void	lst_short(t_list **next, char *name, struct dirent *t)
{
	ft_lstadd(next, ft_lstnew(ft_strjoin(name, t->d_name),
				ft_strlen(name) + GET_L(t)));
}

void	print_internals(t_flag *f, char *n)
{
	t_list			*h;
	t_list			*next;
	DIR				*dir;
	struct dirent	*t;
	struct stat		i;

	h = ft_lstnew(NULL, 0);
	next = ft_lstnew(NULL, 0);
	lstat(n, &i);
	if (permission(i))
		return ;
	if ((dir = opendir(n)))
	{
		while ((t = readdir(dir)))
		{
			if ((f->a == 0 && TO_CHAR(t) != '.') || f->a)
				ft_lstadd(&h, ft_lstnew(ft_strdup(t->d_name), GET_L(t)));
			stat(ft_strjoin(n, t->d_name), &i);
			if ((f->ur && IFDIR(i) && DOTS(t) && DOT(t))
					&& ((!f->a && TO_CHAR(t) != '.') || f->a))
				lst_short(&next, n, t);
		}
		closedir(dir);
		shorten(f, h, next, n);
	}
}

void	process(t_flag *flags, t_list *work)
{
	int			len;
	struct stat	info;
	char		*buff;

	len = lst_len(work);
	sort_lst(flags, &work);
	buff = ft_strnew(PATH_MAX);
	while (work->next)
	{
		if (len > 1 || flags->ur == 1)
		{
			ft_putstr(work->content);
			ft_putstr(":\n");
		}
		if (ft_strcmp(work->content, "/") == 0)
			buff = strdup("/");
		else
			buff = ft_strjoin(work->content, "/");
		stat(buff, &info);
		print_internals(flags, buff);
		work = work->next;
	}
}

int		main(int argc, char **argv)
{
	t_flag	*flags;
	t_list	*dirs;

	flags = get_flags(argc, argv);
	dirs = get_files(argc, argv);
	process(flags, dirs);
}
