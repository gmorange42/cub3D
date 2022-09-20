/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:47 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:54:48 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_put_error("Mlx_init failed\n");
		return (FALSE);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (!data->win)
	{
		ft_put_error("Mlx_new_window failed\n");
		return (FALSE);
	}
	mlx_do_key_autorepeatoff(data->mlx);
	return (TRUE);
}

t_rect	ft_init_rect(int x, int y, int width, int height)
{
	t_rect	rect;

	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return (rect);
}

int	ft_import_textures(t_data *data)
{
	int	i;

	i = 0;
	data->t[0].img = mlx_xpm_file_to_image(data->mlx, data->n, \
			&data->t[0].width, &data->t[0].height);
	data->t[1].img = mlx_xpm_file_to_image(data->mlx, data->s, \
			&data->t[1].width, &data->t[1].height);
	data->t[2].img = mlx_xpm_file_to_image(data->mlx, data->w, \
			&data->t[2].width, &data->t[2].height);
	data->t[3].img = mlx_xpm_file_to_image(data->mlx, data->e, \
			&data->t[3].width, &data->t[3].height);
	if (!data->t[0].img || !data->t[1].img || \
			!data->t[2].img || !data->t[3].img)
		return (FALSE);
	while (i < 4)
	{
		data->t[i].addr = mlx_get_data_addr(data->t[i].img, \
				&data->t[i].bpp, &data->t[i].line_len, \
				&data->t[i].endian);
		i++;
	}
	if (!data->t[0].addr || !data->t[1].addr || \
			!data->t[2].addr || !data->t[3].addr)
		return (FALSE);
	return (TRUE);
}
