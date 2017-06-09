/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:42:27 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/08 19:36:16 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

t_list	*get_files(int argc, char **argv)
{
	t_list	*tmp;
	int		n;
	int		dashes;

	tmp = (t_list*)malloc(sizeof(t_list));
	tmp->next = 0;
	tmp->content = 0;
	n = 1;
	dashes = 0;
	while (n < argc)
	{
		if (argv[n][0] != '-' || dashes)
		{
			ft_lstadd(&tmp, ft_lstnew(argv[n], ft_strlen(argv[n])));
			dashes++;
		}
		n++;
	}
	if (tmp->content == 0)
			ft_lstadd(&tmp, ft_lstnew(".", ft_strlen(".")));
	return (tmp);
}

void	print_lst(t_list *work)
{
	while (work->next)
	{
		ft_putendl(work->content);
		work = work->next;
	}
}

int		main(int argc, char **argv)
{
	t_flag	*work;
	t_list	*dirs;

	work = get_flags(argc, argv);
	dirs = get_files(argc, argv);
	print_lst(dirs);
}
