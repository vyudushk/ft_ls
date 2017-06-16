/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:45:58 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/15 17:45:20 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	del(void *kill, size_t size)
{
	size++;
	free(kill);
}

void	clear_flag(t_flag *tmp)
{
	tmp->ur = 0;
	tmp->l = 0;
	tmp->a = 0;
	tmp->r = 0;
	tmp->t = 0;
}

t_flag	*get_flags(int argc, char **argv)
{
	t_flag	*tmp;
	int		n;
	int		i;

	tmp = (t_flag*)malloc(sizeof(t_flag));
	if (tmp == NULL)
		return (NULL);
	n = 0;
	clear_flag(tmp);
	while (n < argc)
	{
		i = 0;
		if (argv[n][0] == '-')
			while (argv[n][i] != '\0')
			{
				tmp->ur = (tmp->ur || argv[n][i] == 'R') ? 1 : 0;
				tmp->l = (tmp->l || argv[n][i] == 'l') ? 1 : 0;
				tmp->a = (tmp->a || argv[n][i] == 'a') ? 1 : 0;
				tmp->r = (tmp->r || argv[n][i] == 'r') ? 1 : 0;
				tmp->t = (tmp->t || argv[n][i] == 't') ? 1 : 0;
				i++;
			}
		n++;
	}
	return (tmp);
}

t_list	*get_files(int argc, char **argv)
{
	t_list	*tmp;
	int		n;
	int		dashes;

	tmp = ft_lstnew(NULL, 0);
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
		ft_lstadd(&tmp, ft_lstnew(".", 2));
	return (tmp);
}
