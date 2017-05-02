/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyofmain_deletemeltrpls.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/05/02 16:07:03 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include "libft.h"
#include <dirent.h> // DIR and dirent
#include <stdio.h>
#include <sys/stat.h> //stat()
#include <stdlib.h>

int	print_dir(t_flag *options, DIR *new_dir)
{
	t_file	*file;
	t_list	*lst;

	file = (t_file*)malloc(sizeof(t_file));
	if (file == 0)
		return (0);
	lst = 0;
	while ((file->name = readdir(new_dir)))
	{
		stat(file->name->d_name, file->info);
		ft_lstadd(&lst, ft_lstnew(file, sizeof(file)));
	}
	process_lst(lst, options);
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
