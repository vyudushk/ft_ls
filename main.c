/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/31 16:05:41 by vyudushk         ###   ########.fr       */
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
	t_list			*head;

	if (argc == 1)
		new_dir = opendir(".");
	else
		new_dir = opendir(argv[1]);
	file = readdir(new_dir);
	lst = ft_lstnew(file->d_name, ft_strlen(file->d_name));
	head = lst;
	while ((file = readdir(new_dir)))
	{
		lst->next = ft_lstnew(file->d_name, ft_strlen(file->d_name));
		lst = lst->next;
	}
	ft_lstiter(head, print_lst);
	return (0);
}
