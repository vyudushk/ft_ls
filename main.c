/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:42:27 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/10 17:46:00 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	print_internals(t_flag *flags, char *name)
{
	t_list			*hold;
	t_list			*next;
	DIR				*dir;
	struct dirent	*tmp;
	struct stat		info;

	hold = ft_lstnew(NULL, 0);
	next = ft_lstnew(NULL, 0);
	dir = opendir(name);
	while ((tmp = readdir(dir)))
	{
		ft_lstadd(&hold, ft_lstnew(tmp->d_name, ft_strlen(tmp->d_name) + 1));
		stat(ft_strjoin(name, tmp->d_name), &info);
		if (flags->ur && S_ISDIR(info.st_mode) &&
				ft_strcmp(tmp->d_name, "..") != 0 && ft_strcmp(tmp->d_name, ".") != 0)
		{
			ft_lstadd(&next, ft_lstnew(ft_strjoin(name, tmp->d_name),
						ft_strlen(name) + ft_strlen(tmp->d_name) + 1));
		}
	}
	print_list(flags, hold);
	ft_putchar('\n');
	if (flags->ur)
	{
		process(flags, next);
	}
}

void	process(t_flag *flags, t_list *work)
{
	int	len;
	int	count;

	sort_lst(flags, &work);
	len = lst_len(work);
	count = len;
	while (work->next)
	{
		if (len > 1 || flags->ur == 1)
		{
			ft_putstr(work->content);
			ft_putstr(":\n");
		}
		print_internals(flags, ft_strjoin(work->content, "/"));
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
