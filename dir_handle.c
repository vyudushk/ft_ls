/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:42:35 by vyudushk          #+#    #+#             */
/*   Updated: 2017/04/19 10:17:25 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>

DIR	*find_dir(int argc, char **argv)
{
	int	n;

	if (argc == 1)
		return (opendir("."));
	n = 1;
	while (n < argc && argv[n][0] == '-')
		n++;
	if (n == argc)
		return (opendir("."));
	return (opendir(argv[n]));
}
