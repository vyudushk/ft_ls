/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:32:15 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/21 17:08:10 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 0 + '0' && c <= 9 + '0')
		return (1);
	else
		return (0);
}
