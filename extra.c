/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:02:54 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/13 23:06:03 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

t_list	*rev_list(t_list *input)
{
	t_list	*res;

	ft_lstnew(NULL, 0);
	while (input->next->content)
	{
		ft_lstadd(&res, ft_lstnew(input->content, input->content_size));
		input = input->next;
	}
	return (res);
}

void	print_permissions(struct stat info)
{
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

void	ft_printtab(int tab, char *str)
{

	tab = tab - ft_strlen(str);
	while (tab--)
	{
		ft_putchar(' ');
		if (tab < 0)
			break;
	}
	ft_putstr(str);
	ft_putchar(' ');
}

void	print_long(char *name, int tab, int linktab)
{
	struct stat		info;
	struct passwd	*pwd;
	struct group	*grp;

	stat(name, &info);
	pwd = getpwuid(info.st_uid);
	grp = getgrgid(info.st_gid);
	print_permissions(info);
	ft_printtab(linktab, ft_itoa(info.st_nlink));
	ft_putstr(pwd->pw_name);
	ft_putstr("  ");
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
	ft_printtab(tab, ft_itoa(info.st_size));
	ft_puttime(ctime(&info.st_mtime));
	ft_putchar(' ');
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

void	print_list(t_flag *flags, t_list *work, char *name)
{
	int	tab;
	int	linktab;

	sort_lst(flags, &work);
	tab = get_tab(work, name);
	linktab = get_link_tab(work, name);
	while (work->next)
	{
		if (flags->l)
		{
			print_long(ft_strjoin(name, work->content), tab, linktab);
		}
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
