/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/31 21:48:28 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include "libft.h"
#include <dirent.h> //opendir and readdir

int main(int argc, char **argv)
{
	DIR				*new_dir;
	struct dirent	*file;
	t_list			*lst;
	char			*dir_name;

	if (argc == 1)
		new_dir = opendir(".");
	else (argc == 2)
		new_dir = opendir(argv[1]);
	else (argc > 2)
	{
		if (argv[1][0] == '-')
			//parse for commands
	}
	valid_check(new_dir, argv[1]);
	while ((file = readdir(new_dir)))
		ft_lstadd(&lst, ft_lstnew(file->d_name, ft_strlen(file->d_name)));
	sort_lst(&lst);
	ft_lstiter(lst, print_lst);
	return (0);
}
