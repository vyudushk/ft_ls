/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:31:07 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/29 14:33:13 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*res_gen(char **hold_c)
{
	char	*res;
	char	*tmp;
	int		i;

	if (hold_c == NULL)
		return (NULL);
	i = 0;
	while (hold_c[0][i] != '\n' && hold_c[0][i] != 0)
		i++;
	res = ft_strsub(*hold_c, 0, i);
	i++;
	tmp = *hold_c;
	*hold_c = ft_strdup(*hold_c + i);
	free(tmp);
	return (res);
}

static char	*fill_hold(char **hold_i, char *buff, int ret_read)
{
	char	*res;
	char	*hold;
	int		fir;
	int		len;

	hold = *hold_i;
	res = (char*)malloc(ft_strlen(hold) + ft_strlen(buff) + 1);
	if (res == NULL)
		return (0);
	fir = 0;
	len = ft_strlen(hold);
	while (len--)
		res[fir++] = *hold++;
	while (ret_read--)
		res[fir++] = *buff++;
	res[fir] = 0;
	free(*hold_i);
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	static char		*hold = 0;
	static int		old_fd = 0;
	int				ret_read;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || fd == 1 || fd == 2)
		return (-1);
	if (hold == 0 || old_fd != fd)
		hold = ft_strdup("");
	old_fd = fd;
	ret_read = 1;
	while (ret_read > 0 && ft_strchr(hold, '\n') == NULL)
	{
		ret_read = read(fd, buff, BUFF_SIZE);
		if (ret_read == -1)
			return (-1);
		buff[ret_read] = 0;
		hold = fill_hold(&hold, buff, ret_read);
	}
	if (ret_read == 0 && ft_strlen(hold) == 0)
		return (0);
	*line = res_gen(&hold);
	return (1);
}
