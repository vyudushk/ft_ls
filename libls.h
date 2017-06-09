/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:15:16 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/09 14:55:29 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H

# include "libft/libft.h"
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>

typedef struct	s_flag
{
	int	ur;
	int	l;
	int	a;
	int	r;
	int	t;
}				t_flag;

t_flag			*get_flags(int argc, char **argv);
t_list			*get_files(int argc, char **argv);

void			process(t_flag *flag, t_list *work);

void			print_list(t_list *work);
int				lst_len(t_list *head);

#endif
