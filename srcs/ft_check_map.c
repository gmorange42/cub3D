/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:50:14 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:50:27 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_check_char("NSWE", data->map[i][j]) == TRUE)
			{
				if (data->p.dir)
					return (FALSE);
				data->p.dir = data->map[i][j];
				data->p.x = j;
				data->p.y = i;
				data->map[i][j] = 'X';
			}
			j++;
		}
		i++;
	}
	if (!data->p.dir)
		return (FALSE);
	return (TRUE);
}

int	ft_flood(char **map, int i, int j)
{
	if (map[i][j] == '0')
		map[i][j] = 'X';
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'X')
		if (map[i][j + 1] == ' ' || ft_flood(map, i, j + 1) == FALSE)
			return (FALSE);
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'X')
		if (map[i][j - 1] == ' ' || ft_flood(map, i, j - 1) == FALSE)
			return (FALSE);
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'X')
		if (map[i + 1][j] == ' ' || ft_flood(map, i + 1, j) == FALSE)
			return (FALSE);
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'X')
		if (map[i - 1][j] == ' ' || ft_flood(map, i - 1, j) == FALSE)
			return (FALSE);
	return (TRUE);
}
