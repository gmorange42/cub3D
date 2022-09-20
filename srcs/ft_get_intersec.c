/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_intersec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:51:11 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:51:12 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_get_dist(double x1, double y1, double x2, double y2)
{
	double	res;

	res = sqrtf(powf(x1 - x2, 2.) + powf(y1 - y2, 2.));
	return (res);
}

void	ft_reset(t_ray *ray)
{
	ray->up = FALSE;
	ray->down = FALSE;
	ray->left = FALSE;
	ray->right = FALSE;
	ray->h_x = 0;
	ray->h_y = 0;
	ray->v_x = 0;
	ray->v_y = 0;
	ray->found_h = FALSE;
	ray->found_v = FALSE;
	ray->dist_h = 0;
	ray->dist_v = 0;
	ray->x = 0;
	ray->y = 0;
	ray->len = 0;
	ray->text_x = 0;
	ray->text_y = 0;
}

void	ft_set_ray_x_y(t_ray *ray)
{
	if ((ray->found_h == TRUE && ray->found_v == FALSE) || \
		(ray->found_h == TRUE && ray->dist_h <= ray->dist_v))
	{
		ray->len = ray->dist_h;
		ray->x = ray->h_x;
		ray->y = ray->h_y;
		if (ray->down == TRUE)
			ray->texture = 0;
		else
			ray->texture = 1;
	}
	else if ((ray->found_v == TRUE && ray->found_h == FALSE) || \
		(ray->found_v == TRUE && ray->dist_v <= ray->dist_h))
	{
		ray->len = ray->dist_v;
		ray->x = ray->v_x;
		ray->y = ray->v_y;
		if (ray->right == TRUE)
			ray->texture = 2;
		else
			ray->texture = 3;
	}
	if (ray->len == 0)
		ray->len = 1;
}

int	ft_get_intersec(t_data *data, t_ray *ray)
{
	ft_reset(ray);
	if (data->p.ray > 0 && data->p.ray < M_PI)
		ray->down = TRUE;
	else
		ray->up = TRUE;
	if (data->p.ray > M_PI / 2 && data->p.ray < M_PI + (M_PI / 2))
		ray->left = TRUE;
	else
		ray->right = TRUE;
	ft_check_h(data, ray);
	ft_check_v(data, ray);
	ray->dist_h = ft_get_dist(ray->h_x, ray->h_y, data->p.x, data->p.y);
	ray->dist_v = ft_get_dist(ray->v_x, ray->v_y, data->p.x, data->p.y);
	ft_set_ray_x_y(ray);
	return (TRUE);
}
