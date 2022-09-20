/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:55:09 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:55:10 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_draw_dir(t_data *data, t_img *img)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = data->p.x * MINI + (cos(data->p.rotate_angle) * i);
	y = data->p.y * MINI + (sin(data->p.rotate_angle) * i);
	if (!data->win)
		return (ft_put_error("Error with window\n"));
	while (i < MINI - 1)
	{
		ft_pxl_put(img, x, y, BLUE);
		i++;
		x = (data->p.x * MINI + (cos(data->p.rotate_angle) * i));
		y = (data->p.y * MINI + (sin(data->p.rotate_angle) * i));
	}
	return (TRUE);
}

int	ft_draw_fov(t_data *data, t_img *img, t_ray ray)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = data->p.x * MINI + (cos(ray.dir) * i);
	y = data->p.y * MINI + (sin(ray.dir) * i);
	if (!data->win)
		return (ft_put_error("Error with window\n"));
	while (i < ray.len * MINI)
	{
		ft_pxl_put(img, x, y, RED);
		i++;
		x = data->p.x * MINI + (cos(ray.dir) * i);
		y = data->p.y * MINI + (sin(ray.dir) * i);
	}
	return (TRUE);
}

int	ft_draw_p(t_data *data)
{
	int		i;
	t_rect	rect;

	i = 0;
	rect = ft_init_rect((data->p.x) * MINI - 1, (data->p.y) * MINI - 1, 3, 3);
	while (i < WIDTH)
	{
		if (ft_draw_fov(data, &data->img, data->rays[i]) == FALSE)
			return (FALSE);
		i++;
	}
	if (ft_draw_dir(data, &data->img) == FALSE)
		return (FALSE);
	if (ft_draw_rect(data, &data->img, rect, RED) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_spawn_p(t_data *data)
{
	data->p.x -= 0.5;
	data->p.y -= 0.5;
	if (data->p.dir == 'N')
		data->p.rotate_angle = M_PI + M_PI_2;
	if (data->p.dir == 'S')
		data->p.rotate_angle = M_PI_2;
	if (data->p.dir == 'W')
		data->p.rotate_angle = M_PI;
	if (data->p.dir == 'E')
		data->p.rotate_angle = M_PI * 2;
	return (TRUE);
}

int	ft_draw_map2d(t_data *data)
{
	int		i;
	int		j;
	int		ret;
	t_rect	rect;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ret = TRUE;
			rect = ft_init_rect((j - 1) * MINI, (i - 1) * MINI, MINI, MINI);
			if (data->map[i][j] == '1')
				ret = ft_draw_rect(data, &data->img, rect, BLACK);
			else if (data->map[i][j] == 'X')
				ret = ft_draw_rect(data, &data->img, rect, WHITE);
			if (ret == FALSE)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
