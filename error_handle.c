/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 21:07:11 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/31 21:10:19 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h> //DIR type
#include <stdlib.h> //exit
#include "libft.h"

void	valid_check(DIR *new_dir, char *dir_name)
{
	if (!new_dir)
	{
		ft_putstr("ls: ");
		ft_putstr(dir_name);
		ft_putstr(": No Such file or direcotry\n");
		exit(0);
	}
}

