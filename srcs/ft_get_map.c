/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:51:16 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:51:18 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_add_to_tab(t_data *data)
{
	int		i;
	char	**tab_tmp;

	i = 0;
	tab_tmp = NULL;
	data->nb_line += 1;
	if (ft_strlen(data->line) > data->line_len)
		data->line_len = ft_strlen(data->line);
	tab_tmp = malloc(sizeof(char *) * (data->nb_line + 1));
	ft_check_malloc(data, tab_tmp);
	while (i < data->nb_line - 1)
	{
		tab_tmp[i] = ft_strdup(data, data->map[i], -1, FALSE);
		i++;
	}
	tab_tmp[i] = ft_strdup(data, data->line, -1, FALSE);
	tab_tmp[i + 1] = NULL;
	ft_free_arr(data->map);
	return (tab_tmp);
}

char	**ft_fill_background(t_data *data)
{
	char	**tab_tmp;
	int		i;
	int		j;

	i = 0;
	tab_tmp = NULL;
	tab_tmp = malloc(sizeof(char *) * (data->nb_line + 3));
	ft_check_malloc(data, tab_tmp);
	while (i < data->nb_line + 2)
	{
		j = 0;
		tab_tmp[i] = malloc(sizeof(char) * (data->line_len + 3));
		while (j < data->line_len + 2)
		{
			tab_tmp[i][j] = ' ';
			j++;
		}
		tab_tmp[i][j] = '\0';
		i++;
	}
	tab_tmp[i] = NULL;
	return (tab_tmp);
}

char	**ft_add_outline(t_data *data)
{
	char	**tab_tmp;
	int		i;
	int		j;

	tab_tmp = NULL;
	i = 0;
	tab_tmp = ft_fill_background(data);
	while (data->map && data->map[i] && tab_tmp && tab_tmp[i + 1])
	{
		j = 0;
		while (data->map[i][j] && tab_tmp[i + 1][j + 1])
		{
			tab_tmp[i + 1][j + 1] = data->map[i][j];
			j++;
		}
		i++;
	}
	ft_free_arr(data->map);
	return (tab_tmp);
}

int	ft_parse_map(t_data *data, int in_map)
{
	while (ft_gnl(data, &data->line) > 0)
	{
		if (ft_check_chars(data->line, " 01NSEW") == TRUE)
		{
			if (ft_check_char(data->line, '1'))
			{
				in_map = TRUE;
				data->map = ft_add_to_tab(data);
			}
			else if (in_map == TRUE)
				return (ft_put_error("Invalid map\n"));
		}
		else
			return (ft_put_error("Invalid chars\n"));
		free(data->line);
	}
	return (TRUE);
}

int	ft_get_map(t_data *data)
{
	int	in_map;

	in_map = FALSE;
	if (ft_parse_map(data, in_map) == FALSE)
		return (FALSE);
	data->map = ft_add_outline(data);
	if (data->nb_line > 300 || data->line_len > 300)
		return (ft_put_error("Invalid map\n"));
	return (TRUE);
}
