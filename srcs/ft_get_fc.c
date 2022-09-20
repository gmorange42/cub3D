/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:51:05 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:51:06 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_fc(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == ',' || str[i] == ' ' || ft_isdigit(str[i]) == TRUE)
		{
			if (str[i] == ',')
				count += 1;
			i++;
		}
		else
			return (FALSE);
	}
	if (count > 2)
		return (FALSE);
	return (TRUE);
}

int	ft_get_c_value(t_data *data, char *str, int *i, int j)
{
	int	k;

	if (j == 0 && data->c[3] == 1)
		return (FALSE);
	k = *i;
	while (str && str[k] && ft_isdigit(str[k]) == TRUE)
		k++;
	k -= *i;
	if (k > 3)
		return (FALSE);
	data->c[j] = ft_atoi(str + *i);
	*i += k;
	if (data->c[j] > 255)
		return (FALSE);
	data->c[3] = 1;
	return (TRUE);
}

int	ft_get_f_value(t_data *data, char *str, int *i, int j)
{
	int	k;

	if (j == 0 && data->f[3] == 1)
		return (FALSE);
	k = *i;
	while (str && str[k] && ft_isdigit(str[k]) == TRUE)
		k++;
	k -= *i;
	if (k > 3)
		return (FALSE);
	data->f[j] = ft_atoi(str + *i);
	*i += k;
	if (data->f[j] > 255)
		return (FALSE);
	data->f[3] = 1;
	return (TRUE);
}

int	ft_cpy_color(t_data *data, char *str, int *i, int j)
{
	if (ft_isdigit(str[*i]) == FALSE)
		return (FALSE);
	if (str[0] == 'F' && ft_get_f_value(data, str, i, j) == FALSE)
		return (FALSE);
	else if (str[0] == 'C' && ft_get_c_value(data, str, i, j) == FALSE)
		return (FALSE);
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	if (j < 2 && str[*i] != ',')
		return (FALSE);
	if (j < 2 && str[*i] == ',')
		*i += 1;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	return (TRUE);
}

int	ft_get_fc(t_data *data, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strncmp(str, "F ", 2) == TRUE || ft_strncmp(str, "C ", 2) == TRUE)
	{
		if (ft_check_fc(str + 2) == FALSE)
			return (FALSE);
		i = 1;
		while (str && str[i] && str[i] == ' ')
			i++;
		while (str[i] && j < 3)
		{
			if (ft_cpy_color(data, str, &i, j) == FALSE)
				return (FALSE);
			j++;
		}
		if (str[i] || j != 3)
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}
