/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/04/27 15:07:48 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include "libft.h"
#include <dirent.h> // DIR and dirent
#include <stdio.h>
#include <sys/stat.h> //stat()

int	main(int argc, char **argv)
{
	DIR				*new_dir;
	struct dirent	*file;
	t_list			*lst;
	t_flag			*options;
	struct stat		buf;

	options = parse_flags(argc, argv);
	new_dir = find_dir(argc, argv);
	valid_check(new_dir, argv[1]);
	while ((file = readdir(new_dir)))
	{
		//ft_lstadd(&lst, ft_lstnew(file->d_name, ft_strlen(file->d_name)));
		stat(file->d_name, &buf);
		ft_putnbr(S_ISDIR(buf.st_mode));
		ft_putchar('\n');
		ft_lstadd(&lst, ft_lstnew(file, sizeof(struct dirent)));
	}
	process_lst(lst, options);
	return (0);
}
