/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/05/15 15:23:24 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include "libft.h"
#include <dirent.h> // DIR and dirent
#include <stdio.h>
#include <sys/stat.h> //stat()
#include <stdlib.h>

int	print_dir(t_flag *opt, DIR *new_dir)
{
	t_file	*file;
	t_list	*lst;
	t_list	*lst_dir;
	DIR		*hold;

	file = 0;
	file = (t_file*)malloc(sizeof(t_file));
	if (file == 0)
		return (0);
	lst = 0;
	lst_dir = 0;
	while ((file->name = readdir(new_dir)))
	{
		stat(file->name->d_name, &file->info);
		ft_lstadd(&lst, ft_lstnew(file, sizeof(file)));
		if (opt->recur && GET_NAME(lst)[0] != '.' && S_ISDIR(file->info.st_mode))
		{
			//printf("TEST-: %s : %i\n", GET_NAME(lst), S_ISDIR(file->info.st_mode));
			ft_putstr("This is DIR: ");
			ft_putendl(GET_NAME(lst));
			ft_lstadd(&lst_dir, ft_lstnew(file, sizeof(file)));
		}
	}
	process_lst(lst, opt);
	if (opt->recur)
		sort_lst(&lst_dir, opt);
	while (opt->recur && lst_dir)
	{
		if ((hold = opendir(GET_NAME(lst_dir))))
		{
			ft_putstr("\n./");
			ft_putstr(GET_NAME(lst_dir));
			ft_putstr(":\n");
			print_dir(opt, hold);
		}
		lst_dir = lst_dir->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	DIR				*new_dir;
	t_flag			*options;

	options = parse_flags(argc, argv);
	new_dir = find_dir(argc, argv);
	valid_check(new_dir, argv[1]);
	print_dir(options, new_dir);
	return (0);
}
