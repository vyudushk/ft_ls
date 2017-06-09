/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:15:16 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/08 17:47:41 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct	s_flag
{
	int	ur;
	int	l;
	int	a;
	int	r;
	int	t;
}				t_flag;

t_flag			*get_flags(int argc, char **argv);

#endif
