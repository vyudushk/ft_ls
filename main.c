/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/04/24 21:22:37 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include "libft.h"
#include <dirent.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	DIR				*new_dir;
	struct dirent	*file;
	t_list			*lst;
	t_flag			*options;

	options = parse_flags(argc, argv);
	new_dir = find_dir(argc, argv);
	valid_check(new_dir, argv[1]);
	while ((file = readdir(new_dir)))
	{
		//ft_lstadd(&lst, ft_lstnew(file->d_name, ft_strlen(file->d_name)));
		ft_lstadd(&lst, ft_lstnew(file, sizeof(struct dirent)));
	}
	process_lst(lst, options);
	return (0);
}
