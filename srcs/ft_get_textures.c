/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:51:23 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:54:00 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count_token(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
			count += 1;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

int	ft_get_textures(t_data *data, char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = ft_count_token(str);
	if (count != 2)
		return (FALSE);
	if (!ft_strncmp(str, "NO ", 3) && !ft_strncmp(str, "SO ", 3) && \
			!ft_strncmp(str, "WE ", 3) && !ft_strncmp(str, "EA ", 3))
		return (FALSE);
	i += 2;
	while (str[i] && str[i] == ' ')
		i++;
	j = ft_get_len(str + i);
	if (str[0] == 'N' && ft_n_texture(data, str + i, j, FALSE) == FALSE)
		return (FALSE);
	else if (str[0] == 'S' && ft_s_texture(data, str + i, j, FALSE) == FALSE)
		return (FALSE);
	else if (str[0] == 'W' && ft_w_texture(data, str + i, j, FALSE) == FALSE)
		return (FALSE);
	else if (str[0] == 'E' && ft_e_texture(data, str + i, j, FALSE) == FALSE)
		return (FALSE);
	return (TRUE);
}
