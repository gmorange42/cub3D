/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:50:58 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:50:59 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	ft_free_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->t[i].img)
			mlx_destroy_image(data->mlx, data->t[i].img);
		i++;
	}
	if (data->mlx && data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
}

void	ft_free(t_data *data)
{
	ft_free_img(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	if (data->mlx)
	{
		mlx_do_key_autorepeaton(data->mlx);
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	data->mlx = NULL;
	free(data->line);
	free(data->tmp);
	data->tmp = NULL;
	ft_free_arr(data->map);
	free(data->n);
	free(data->s);
	free(data->w);
	free(data->e);
	if (data->fd >= 0)
		close(data->fd);
}
