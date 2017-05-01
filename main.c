/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/05/01 15:31:28 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include "libft.h"
#include <dirent.h> // DIR and dirent
#include <stdio.h>
#include <sys/stat.h> //stat()
#include <stdlib.h>

int	main(int argc, char **argv)
{
	DIR				*new_dir;
	t_list			*lst;
	t_flag			*options;
	t_file			*file;

	options = parse_flags(argc, argv);
	new_dir = find_dir(argc, argv);
	valid_check(new_dir, argv[1]);
	file = (t_file*)malloc(sizeof(t_file));
	while ((file->name = readdir(new_dir)))
	{
		stat(file->name->d_name, file->info);
		ft_lstadd(&lst, ft_lstnew(file, sizeof(file)));
	}
	process_lst(lst, options);
	return (0);
}
