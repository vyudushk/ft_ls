/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 12:14:00 by vyudushk          #+#    #+#             */
/*   Updated: 2017/05/16 11:58:20 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libls.h"

t_flag	*new_t_flag(void)
{
	t_flag	*res;

	res = (t_flag*)malloc(sizeof(t_flag));
	if (res == 0)
		return (NULL);
	res->long_format = 0;
	res->recur = 0;
	res->include_dot = 0;
	res->rev = 0;
	res->time = 0;
	return (res);
}

void	set_flag(t_flag *flags, char c)
{
	if (c == 'l')
		flags->long_format = 1;
	if (c == 'R')
		flags->recur = 1;
	if (c == 'a')
		flags->include_dot = 1;
	if (c == 'r')
		flags->rev = 1;
	if (c == 't')
		flags->time = 1;
}

int		isflags(t_flag *opt)
{
	int	n;

	n = 0;	
	n += opt->long_format ? 1 : 0;
	n += opt->recur ? 1 : 0;
	n += opt->include_dot ? 1 : 0;
	n += opt->rev ? 1 : 0;
	n += opt->time ? 1 : 0;
	return (n);
}

t_flag	*parse_flags(int argc, char **argv)
{
	t_flag	*flags;
	int		i;
	int		n;

	flags = new_t_flag();
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		n = 0;
		while (argv[i][n] != 0)
		{
			set_flag(flags, argv[i][n]);
			n++;
		}
		i++;
	}
	return (flags);
}
