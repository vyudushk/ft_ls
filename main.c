/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/31 16:10:26 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <dirent.h> //opendir and readdir

void	print_lst(t_list *lst)
{
	ft_putendl(lst->content);
}

int main(int argc, char **argv)
{
	DIR				*new_dir;
	struct dirent	*file;
	t_list			*lst;

	if (argc == 1)
		new_dir = opendir(".");
	else
		new_dir = opendir(argv[1]);
	while ((file = readdir(new_dir)))
		ft_lstadd(&lst, ft_lstnew(file->d_name, ft_strlen(file->d_name)));
	ft_lstiter(lst, print_lst);
	return (0);
}
