/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/08 13:44:52 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include "libft.h"
#include <dirent.h> // DIR and dirent
#include <stdio.h>
#include <sys/stat.h> //stat()
#include <stdlib.h>

void	collect_names(t_flag *work, DIR *new_dir)
{
	t_list			*tmp;
	struct dirent	*name;

	tmp = malloc(sizeof(t_list));
	while ((name = readdir(new_dir)))
	{
		ft_lstadd(&tmp, ft_lstnew(ft_strdup(name->d_name), ft_strlen(name->d_name)));
	}
	work->dirs = tmp;
}

t_list	*catch_args(t_flag *work, int argc, char **argv)
{
	t_list	*tmp;
	int		i;
	t_flag	*hold;

	i = 0;
	while (i < argc && argv[i][0] == '-')
		i++;
	if (i == argc)
		return (ft_lstnew(".", ft_strlen(".")));
	else
	{
		while (i < argc)
		{
			ft_lstadd(&tmp, ft_lstnew(argv[i], ft_strlen(argv[i])));
			i++;
		}
		hold = 0;
		hold = ft_memcpy(hold, work, sizeof(work));
		free(work->dirs);
		work->dirs = tmp;
		sort_lst(hold);
		return (hold->dirs);
	}
}

int		main(int argc, char **argv)
{
	DIR		*new_dir;
	t_flag	*work;
	//t_list	*args;
	int		n;

	n = 0;
	work = parse_flags(argc, argv);
	//args = catch_args(work, argc, argv);
	while (argv[n][0] == '-')
		n++;
	while (n < argc)
	{
		new_dir = find_dir(argc, argv);
		collect_names(work, new_dir);
		process_lst(work);
		argv++;
		n++;
	}
	return (0);
}
