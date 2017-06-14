/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:42:27 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/14 15:56:51 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

char	*uidget(struct stat info)
{
	struct passwd	*pwd;

	pwd = getpwuid(info.st_uid);
	return (pwd->pw_name);
}

void	print_internals(t_flag *flags, char *name)
{
	t_list			*hold;
	t_list			*next;
	DIR				*dir;
	struct dirent	*t;
	struct stat		info;

	hold = ft_lstnew(NULL, 0);
	next = ft_lstnew(NULL, 0);
	lstat(name, &info);
	if ((S_IRUSR & info.st_mode) == 0 || ((S_IRGRP & info.st_mode) == 0 &&
				ft_strcmp(uidget(info), "root") == 0))
	{
		ft_putstr_fd(" Permission denied\n", 2);
		return ;
	}
	dir = opendir(name);
	while ((t = readdir(dir)))
	{
		if ((flags->a == 0 && t->d_name[0] != '.') || flags->a)
			ft_lstadd(&hold, ft_lstnew(t->d_name, ft_strlen(t->d_name) + 1));
		stat(ft_strjoin(name, t->d_name), &info);
		if ((flags->ur && S_ISDIR(info.st_mode) && ft_strcmp(t->d_name, "..")
		&& ft_strcmp(t->d_name, ".")) && ((!flags->a && t->d_name[0] != '.')
		|| flags->a))
		{
			ft_lstadd(&next, ft_lstnew(ft_strjoin(name, t->d_name),
						ft_strlen(name) + ft_strlen(t->d_name) + 1));
		}
	}
	print_list(flags, hold, name);
	if (flags->ur && lst_len(next))
		process(flags, next);
}

void	process(t_flag *flags, t_list *work)
{
	int			len;
	struct stat	info;
	char		*buff;

	len = lst_len(work);
	sort_lst(flags, &work);
	while (work->next)
	{
		if (len > 1 || flags->ur == 1)
		{
			ft_putstr(work->content);
			ft_putstr(":\n");
		}
		if (ft_strcmp(work->content, "/") == 0)
			buff = ft_strdup("/");
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
