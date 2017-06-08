/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 22:47:43 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/06 21:14:19 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sstrcmp(const char *s1, const char *s2)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	if (s1 == 0 || s2 == 0)
		return (0);
	cmp1 = (unsigned char*)s1;
	cmp2 = (unsigned char*)s2;
	while (*cmp1 && *cmp2 && *cmp1 == *cmp2)
	{
		cmp1++;
		cmp2++;
	}
	return ((*cmp1) - (*cmp2));
}
