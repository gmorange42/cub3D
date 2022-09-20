/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:55:15 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:55:17 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_elem(t_data *data, char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (TRUE);
	if (ft_check_whitespaces(s) == TRUE)
		return (ft_put_error("Whitespaces in files\n"));
	if (s[0] && (s[0] == 'N' || s[0] == 'S' || s[0] == 'W' || s[0] == 'E'))
	{
		if (ft_get_textures(data, s) == FALSE)
			return (ft_put_error("Invalid textures\n"));
	}
	else if (s[0] && (s[0] == 'F' || s[0] == 'C'))
	{
		if (ft_get_fc(data, s) == FALSE)
			return (ft_put_error("Invalid colors\n"));
	}
	else
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i])
			return (ft_put_error("Invalid elem\n"));
	}
	return (TRUE);
}

int	ft_get_elem(t_data *data, char **line)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		ret = ft_gnl(data, line);
		if (line && ft_parse_elem(data, *line) == FALSE)
			return (FALSE);
		free(*line);
		*line = NULL;
		if (data->n && data->s && data->w && data->e && \
				data->f[3] == 1 && data->c[3] == 1)
			ret = 0;
	}
	if (!data->n || !data->s || !data->w || !data->e || \
			data->f[3] != 1 || data->c[3] != 1)
		return (ft_put_error("Missing info\n"));
	return (TRUE);
}

int	ft_convert_color(int red, int green, int blue)
{
	int	color;

	color = red << 16 | green << 8 | blue;
	return (color);
}

int	ft_parse_file(t_data *data)
{
	if (ft_get_elem(data, &data->line) == FALSE)
		return (FALSE);
	if (ft_get_map(data) == FALSE)
		return (FALSE);
	if (ft_check_player(data) == FALSE)
		return (ft_put_error("Invalid map\n"));
	if (ft_flood(data->map, data->p.y, data->p.x) == FALSE)
		return (ft_put_error("Map not closed\n"));
	data->c[3] = ft_convert_color(data->c[0], data->c[1], data->c[2]);
	data->f[3] = ft_convert_color(data->f[0], data->f[1], data->f[2]);
	return (TRUE);
}
