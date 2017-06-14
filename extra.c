/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:02:54 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/14 16:50:19 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	print_permissions(struct stat info, struct stat lfo)
{
	if (S_ISLNK(lfo.st_mode))
	{
		ft_putchar('l');
		info = lfo;
	}
	else
		ft_putchar(S_ISDIR(info.st_mode) ? 'd' : '-');
	ft_putchar(S_IRUSR & info.st_mode ? 'r' : '-');
	ft_putchar(S_IWUSR & info.st_mode ? 'w' : '-');
	ft_putchar(S_IXUSR & info.st_mode ? 'x' : '-');
	ft_putchar(S_IRGRP & info.st_mode ? 'r' : '-');
	ft_putchar(S_IWGRP & info.st_mode ? 'w' : '-');
	ft_putchar(S_IXGRP & info.st_mode ? 'x' : '-');
	ft_putchar(S_IROTH & info.st_mode ? 'r' : '-');
	ft_putchar(S_IWOTH & info.st_mode ? 'w' : '-');
	ft_putchar(S_IXOTH & info.st_mode ? 'x' : '-');
	ft_putstr("  ");
}

void	ft_puttime(char *str)
{
	int	i;

	i = 0;
	str = str + 4;
	while (str[i] != '\n')
		i++;
	i = i - 8;
	write(1, str, i);
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

void	print_link(char *name)
{
	char	*hold;

	hold = ft_strnew(PATH_MAX);
	readlink(name, hold, PATH_MAX - 1);
	ft_putstr(" -> ");
	ft_putstr(hold);
	free(hold);
}

void	print_long(char *name, t_tab tabs, struct stat lfo, char *work)
{
	struct stat		info;
	struct passwd	*pwd;
	struct group	*grp;

	stat(name, &info);
	if (S_ISLNK(lfo.st_mode))
		info = lfo;
	pwd = getpwuid(info.st_uid);
	grp = getgrgid(info.st_gid);
	print_permissions(info, lfo);
	ft_printtab(tabs.linktab, ft_itoa(info.st_nlink), 0);
	ft_printtab(tabs.nametab, pwd->pw_name, 1);
	ft_putstr(" ");
	ft_printtab(tabs.grouptab, grp->gr_name, 1);
	ft_putstr(" ");
	ft_printtab(tabs.tab, ft_itoa(info.st_size), 0);
	ft_puttime(ctime(&info.st_mtime));
	ft_putchar(' ');
	ft_putstr(work);
	if (S_ISLNK(lfo.st_mode))
		print_link(name);
	ft_putchar('\n');
}

void	print_list(t_flag *flags, t_list *work, char *name)
{
	t_tab	tabs;
	struct stat lfo;

	sort_lst(flags, &work);
	tabs.tab = get_tab(work, name);
	tabs.linktab = get_link_tab(work, name);
	tabs.nametab = get_name_tab(work, name);
	tabs.grouptab = get_group_tab(work, name);
	while (work->next)
	{
		if (flags->l)
		{
			lstat(ft_strjoin(name, work->content), &lfo);
			print_long(ft_strjoin(name, work->content), tabs, lfo, work->content);
		}
		else
			ft_putendl(work->content);
		work = work->next;
	}
	ft_putchar('\n');
}

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
