/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:31:21 by vyudushk          #+#    #+#             */
/*   Updated: 2017/05/16 11:58:29 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <dirent.h>
#include <libft.h>
#include <stdlib.h>

void	print_dir(char* dir_name, t_flag *opt)
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
	sort_lst(&lst, opt);
	ft_lstiter(lst, print_lst);
}

int		main(int argc, char **argv)
{
	int		n;
	t_flag	*opt;

	n = 1;
	opt	= parse_flags(argc, argv);
	if (argc == 1)
		print_dir(".", opt);
	else
		while (n < argc)
		{
			if (argc > 2)
			{
				ft_putstr(argv[n]);
				ft_putstr(":\n");
			}
			print_dir(argv[n++], opt);
			if (n != argc)
				ft_putchar('\n');
		}
}
