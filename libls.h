/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:15:16 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/14 11:32:45 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H

# include "libft/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <limits.h>

# define GET_NANOSEC(info) info.st_mtimespec.tv_nsec

typedef struct	s_flag
{
	int	ur;
	int	l;
	int	a;
	int	r;
	int	t;
}				t_flag;

typedef struct	s_tab
{
	int	tab;
	int	linktab;
	int	nametab;
	int	grouptab;
}				t_tab;

t_flag			*get_flags(int argc, char **argv);
t_list			*get_files(int argc, char **argv);

void			process(t_flag *flag, t_list *work);

void			print_list(t_flag *flags, t_list *work, char *name);
int				lst_len(t_list *head);
void			sort_lst(t_flag *flags, t_list **work);

#endif
