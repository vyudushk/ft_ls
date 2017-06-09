/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:42:27 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/09 15:25:13 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	print_internals(t_flag *flags, char *name)
{
	t_list			*hold;
	t_list			*next;
	DIR				*dir;
	struct dirent	*tmp;
	struct stat		filestat;

	hold = ft_lstnew(NULL, 0);
	next = ft_lstnew(NULL, 0);
	dir = opendir(name);
		while ((tmp = readdir(dir)))
		{
			ft_lstadd(&hold, ft_lstnew(tmp->d_name, ft_strlen(tmp->d_name) + 1));
			stat(ft_strjoin(name, tmp->d_name), &filestat);
			if (flags->ur && S_ISDIR(filestat.st_mode) && ft_strcmp(tmp->d_name, "..") != 0 && ft_strcmp(tmp->d_name, ".") != 0)
			{
				ft_lstadd(&next, ft_lstnew(ft_strjoin(name, tmp->d_name), ft_strlen(name) + ft_strlen(tmp->d_name) + 1));
				ft_putendl(tmp->d_name);
			}
		}
	print_list(hold);
	ft_putchar('\n');
	if (flags->ur)
		process(flags, next);
}

void	process(t_flag *flags, t_list *work)
{
	int	len;
	int	count;

	len = lst_len(work);
	count = len;
	while (work->next)
	{
		ft_putstr(work->content);
		ft_putstr(":\n");
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
