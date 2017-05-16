/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:31:21 by vyudushk          #+#    #+#             */
/*   Updated: 2017/05/15 16:29:20 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <dirent.h>
#include <libft.h>
#include <stdlib.h>

void	print_dir(int argc, char* dir_name)
{
	DIR		*ds;
	t_list	*lst;
	t_file	*file;

	ds = opendir(dir_name);
	lst = 0;
	file = 0;
	file = (t_file*)malloc(sizeof(t_file));
	if (file == 0)
		return ;
	while ((file->name = readdir(ds)))
	{
		ft_lstadd(&lst, ft_lstnew(file, sizeof(t_file)));
	}
	if (argc > 2)
	{
		ft_putstr(dir_name);
		ft_putstr(":\n");
	}
	print_lst(lst);
}

int		main(int argc, char **argv)
{
	t_flag	*opt;
	int		n;

	opt = parse_flags(argc, argv);
	if (!isflags(opt))
	{
		n = 1;
		while (n < argc)
		{
			print_dir(argc, argv[n]);
			n++;
		}
	}
}
