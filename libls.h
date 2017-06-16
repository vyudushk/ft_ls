/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:15:16 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/15 17:45:46 by vyudushk         ###   ########.fr       */
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
# include <stdio.h>
# include <errno.h>

# define GET_NANOSEC(info) info.st_mtimespec.tv_nsec
# define GET_RUS(info) !S_IRUSR & info.st_mode
# define TO_CHAR(tmp) tmp->d_name[0]
# define GET_L(tmp) ft_strlen(tmp->d_name) + 1
# define DOTS(tmp) ft_strcmp(tmp->d_name, "..")
# define DOT(tmp) ft_strcmp(tmp->d_name, ".")
# define IFDIR(info) S_ISDIR(info.st_mode)

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

char			*uidget(struct stat info);
void			del(void *kill, size_t size);
void			shorten(t_flag *flags, t_list *hold, t_list *next, char *name);

void			print_list(t_flag *flags, t_list *work, char *name);
int				lst_len(t_list *head);
void			sort_lst(t_flag *flags, t_list **work);
int				is_sort(t_flag *flags, t_list *work);
int				is_time_sort(t_flag *flags, t_list *work);

int				get_tab(t_list *work, char *name);
int				get_link_tab(t_list *work, char *name);
int				get_name_tab(t_list *work, char *name);
int				get_group_tab(t_list *work, char *name);

void			ft_printtab(int tab, char *str, int mode);

#endif
