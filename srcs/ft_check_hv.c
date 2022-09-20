/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:50:04 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:50:10 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_search_collisions(t_data *data, double *x, double *y)
{
	while (data->intersec.start_x >= 0 && data->intersec.start_y >= 0 && \
		data->intersec.start_x <= data->line_len && \
		data->intersec.start_y <= data->nb_line)
	{
		if (ft_check_walls(data, data->intersec.start_x, \
			data->intersec.start_y, 0) == TRUE || \
			ft_check_walls(data, \
			data->intersec.start_x - data->intersec.flag_x, \
			data->intersec.start_y - data->intersec.flag_y, 0) == TRUE)
		{
			*x = data->intersec.start_x;
			*y = data->intersec.start_y;
			return (TRUE);
		}
		else
		{
			data->intersec.start_x += data->intersec.inc_x;
			data->intersec.start_y += data->intersec.inc_y;
		}
	}
	return (FALSE);
}

int	ft_check_v(t_data *data, t_ray *ray)
{
	data->intersec.start_x = floor(data->p.x);
	if (ray->right == TRUE)
		data->intersec.start_x += 1;
	data->intersec.start_y = data->p.y + \
		((data->intersec.start_x - data->p.x) * tan(data->p.ray));
	data->intersec.inc_x = 1;
	if (ray->left == TRUE)
		data->intersec.inc_x *= -1;
	data->intersec.inc_y = tan(data->p.ray);
	if (ray->up == TRUE && data->intersec.inc_y > 0)
		data->intersec.inc_y *= -1;
	if (ray->down == TRUE && data->intersec.inc_y < 0)
		data->intersec.inc_y *= -1;
	ray->found_v = FALSE;
	data->intersec.flag_x = 1;
	data->intersec.flag_y = 0;
	if (ft_search_collisions(data, &ray->v_x, &ray->v_y) == TRUE)
		ray->found_v = TRUE;
	return (TRUE);
}

int	ft_check_h(t_data *data, t_ray *ray)
{
	data->intersec.start_y = floor(data->p.y);
	if (ray->down == TRUE)
		data->intersec.start_y += 1;
	data->intersec.start_x = data->p.x + \
		((data->intersec.start_y - data->p.y) / tan(data->p.ray));
	data->intersec.inc_y = 1;
	if (ray->up == TRUE)
		data->intersec.inc_y *= -1;
	data->intersec.inc_x = 1 / tan(data->p.ray);
	if (ray->left == TRUE && data->intersec.inc_x > 0)
		data->intersec.inc_x *= -1;
	if (ray->right == TRUE && data->intersec.inc_x < 0)
		data->intersec.inc_x *= -1;
	ray->found_h = FALSE;
	data->intersec.flag_x = 0;
	data->intersec.flag_y = 1;
	if (ft_search_collisions(data, &ray->h_x, &ray->h_y) == TRUE)
		ray->found_h = TRUE;
	return (TRUE);
}
