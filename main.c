/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/31 16:39:07 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <dirent.h> //opendir and readdir

void	print_lst(t_list *lst)
{
	ft_putendl(lst->content);
}

int		is_lst_sort(t_list *lst)
{
	while (lst->next)
	{
		if (ft_strcmp(lst->content, lst->next->content) > 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_lst(t_list **input)
{
	t_list	*lst;
	t_list	*head;
	void	*hold;

	lst = *input;
	head = lst;
	while (is_lst_sort(head) == 0)
	{
		lst = head;
		while (lst->next)
		{
			if (ft_strcmp(lst->content, lst->next->content) > 0)
			{
				hold = lst->content;
				lst->content = lst->next->content;
				lst->next->content = hold;
			}
			lst = lst->next;
		}
	}
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
	sort_lst(&lst);
	ft_lstiter(lst, print_lst);
	return (0);
}
