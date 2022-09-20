/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:26 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:54:27 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_find_nl(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

static int	ft_fill_line(t_data *data, char *buf, char **line)
{
	int		nl;
	char	*tmp;

	nl = -1;
	tmp = NULL;
	data->tmp = ft_strjoin(data, data->tmp, buf);
	nl = ft_find_nl(data->tmp);
	if (nl >= 0)
	{
		*line = ft_strdup(data, data->tmp, nl, FALSE);
		tmp = ft_strdup(data, &data->tmp[nl + 1], -1, FALSE);
		free(data->tmp);
		data->tmp = ft_strdup(data, tmp, -1, FALSE);
		free(tmp);
	}
	return (nl);
}

int	ft_gnl(t_data *data, char **line)
{
	int		ret;
	char	buf[100];

	ret = 1;
	*line = NULL;
	while (ret > 0)
	{
		ret = read(data->fd, buf, 99);
		if (ret == -1)
		{
			ft_put_error(strerror(errno));
			return (ret);
		}
		else if (ret > 0)
		{
			buf[ret] = '\0';
			if (ft_fill_line(data, buf, line) >= 0)
				return (ret);
		}
		if (ret == 0 && ft_fill_line(data, NULL, line) >= 0)
			return (1);
	}
	return (ret);
}
