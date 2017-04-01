/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:36:32 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/31 21:09:49 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H

# include "libft/libft.h"
# include <dirent.h> //DIR type

void	print_lst(t_list *lst);
void	sort_lst(t_list **input);
void	valid_check(DIR *new_dir, char *dir_name);

#endif
