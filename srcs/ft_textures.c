/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:55:26 by echuong           #+#    #+#             */
/*   Updated: 2022/03/17 13:45:26 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_texture_path(char *file)
{
	int		len;
	int		fd;
	char	buf[2];

	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".xpm", -1) == FALSE)
		return (FALSE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	else if (read(fd, buf, 0) == -1)
	{
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

int	ft_n_texture(t_data *data, char *str, int len, int flag)
{
	if (!data->n)
	{
		data->n = ft_strdup(data, str, len, flag);
		if (ft_check_texture_path(data->n) == FALSE)
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

int	ft_s_texture(t_data *data, char *str, int len, int flag)
{
	int	fd;

	fd = 0;
	if (!data->s)
	{
		data->s = ft_strdup(data, str, len, flag);
		if (ft_check_texture_path(data->s) == FALSE)
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

int	ft_w_texture(t_data *data, char *str, int len, int flag)
{
	int	fd;

	fd = 0;
	if (!data->w)
	{
		data->w = ft_strdup(data, str, len, flag);
		if (ft_check_texture_path(data->w) == FALSE)
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

int	ft_e_texture(t_data *data, char *str, int len, int flag)
{
	int	fd;

	fd = 0;
	if (!data->e)
	{
		data->e = ft_strdup(data, str, len, flag);
		if (ft_check_texture_path(data->e) == FALSE)
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}
