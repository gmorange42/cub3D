/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:55:21 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:55:22 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_draw_wall(t_data *data, double height, double x, double y)
{
	int				start;
	int				dist_top;
	unsigned int	*color;

	start = 0;
	while (start < height && y <= HEIGHT)
	{
		dist_top = y + (height / 2) - (HEIGHT / 2);
		data->rays[(int)x].text_y = dist_top * \
			((float)data->t[data->rays[(int)x].texture].height / height);
		color = (unsigned int *)(data->t[data->rays[(int)x].texture].addr + \
			((int)data->rays[(int)x].text_y * \
			data->t[data->rays[(int)x].texture].line_len + \
			(int)data->rays[(int)x].text_x * \
			(data->t[data->rays[(int)x].texture].bpp / 8)));
		ft_pxl_put(&data->img, x, y, *color);
		y++;
		start++;
	}
	return (y);
}

void	ft_draw_column(t_data *data, double x, double y, double height)
{
	int	start;
	int	dist_top;

	if (y < 0)
		y = 0;
	start = 0;
	dist_top = y;
	while (start < y)
	{
		ft_pxl_put(&data->img, x, start, data->c[3]);
		start++;
	}
	y = ft_draw_wall(data, height, x, y);
	while (y < HEIGHT)
	{
		ft_pxl_put(&data->img, x, y, data->f[3]);
		y++;
	}
}

int	ft_render_walls(t_data *data)
{
	int		i;
	double	y;
	double	height;
	double	corrected_len;

	i = 0;
	y = 0;
	while (i < WIDTH)
	{
		corrected_len = data->rays[i].len * \
			(cos(data->rays[i].dir - data->p.rotate_angle));
		height = (1 / corrected_len) * data->dist_pp;
		y = (HEIGHT / 2) - (height / 2);
		if (data->rays[i].len == data->rays[i].dist_h)
			data->rays[i].text_x = fmod(data->rays[i].x, 1) * \
				data->t[data->rays[i].texture].width;
		else
			data->rays[i].text_x = fmod(data->rays[i].y, 1) * \
				data->t[data->rays[i].texture].width;
		ft_draw_column(data, i, y, height);
		i++;
	}
	return (TRUE);
}
