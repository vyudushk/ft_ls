/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:45:58 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/08 17:47:08 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

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
