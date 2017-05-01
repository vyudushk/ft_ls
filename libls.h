/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:36:32 by vyudushk          #+#    #+#             */
/*   Updated: 2017/04/27 15:20:30 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H

# include "libft/libft.h"
# include <dirent.h> //DIR type and struct dirent
# include <sys/stat.h> // 
# define GET_NAME(lst) ((struct dirent*)(lst->content))->d_name

typedef struct	s_flag
{
	int long_format; 
	int	recur;
	int	include_dot;
	int	rev;
	int	time;
}				t_flag;

typedef struct	s_file
{
	struct dirent	*name;
	struct stat		*info;
}				t_file;

void			print_lst(t_list *lst);
void			sort_lst(t_list **input, t_flag *options);
void			valid_check(DIR *new_dir, char *dir_name);
t_flag			*new_t_flag();
void			set_flag(t_flag *flags, char c);
t_flag			*parse_flags(int argc, char **argv);
DIR				*find_dir(int argc, char **argv);

void			process_lst(t_list *lst, t_flag *options);

#endif
