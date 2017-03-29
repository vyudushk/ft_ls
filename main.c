/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:34:41 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/29 14:48:54 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <dirent.h> //opendir and readdir

int main(int argc, char **argv)
{
	DIR				*new_dir;
	struct dirent	*test;

	if (argc == 1)
		new_dir = opendir(".");
	else
		new_dir = opendir(argv[1]);
	test = readdir(new_dir);
	ft_putstr(test->d_name);
	return (0);
}
