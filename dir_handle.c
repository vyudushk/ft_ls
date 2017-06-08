/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:42:35 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/07 12:55:29 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"
#include <dirent.h>

DIR	*find_dir(int argc, char **argv)
{
	int	n;
	DIR	*hold;

	if (argc == 1)
		return (opendir("."));
	n = 1;
	while (n < argc && argv[n][0] == '-')
		n++;
	if (n == argc)
		return (opendir("."));
	hold = opendir(argv[n]);
	valid_check(hold, argv[n]);
	return (hold);
}
