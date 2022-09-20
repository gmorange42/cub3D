/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:40 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:54:42 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_walls(t_data *data, double x, double y, int flag)
{
	int	i;
	int	j;
	int	p_i;
	int	p_j;

	if (x < 0 || y < 0 || x > data->line_len || y > data->nb_line)
		return (TRUE);
	i = floor(y) + 1;
	j = floor(x) + 1;
	p_i = floor(data->p.y) + 1;
	p_j = floor(data->p.x) + 1;
	if (flag == 1 && (data->map[p_i][j] == '1' || \
		data->map[p_i][j] == ' ' || data->map[p_i][j] == '0'))
		return (TRUE);
	if (flag == 1 && (data->map[i][p_j] == '1' || \
		data->map[i][p_j] == ' ' || data->map[i][p_j] == '0'))
		return (TRUE);
	if (data->map[i][j] == '1' || \
		data->map[i][j] == ' ' || data->map[i][j] == '0')
		return (TRUE);
	return (FALSE);
}

int	ft_handle_fov(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		data->p.ray = data->p.rotate_angle + \
			atan((i - WIDTH / 2) / data->dist_pp);
		if (data->p.ray >= 2 * M_PI)
			data->p.ray -= 2 * M_PI;
		if (data->p.ray < 0.)
			data->p.ray += 2 * M_PI;
		data->rays[i].dir = data->p.ray;
		ft_get_intersec(data, &data->rays[i]);
		i++;
	}
	return (TRUE);
}

int	ft_handle_moves(t_data *data)
{
	double	x;
	double	y;
	double	dist_fb;
	double	dist_lr;

	data->p.rotate_angle += data->p.turn * data->p.rotate_speed;
	if (data->p.rotate_angle >= 2 * M_PI)
		data->p.rotate_angle -= 2 * M_PI;
	if (data->p.rotate_angle < 0)
		data->p.rotate_angle += 2 * M_PI;
	dist_fb = data->p.front_back * data->p.move_speed;
	dist_lr = data->p.left_right * data->p.move_speed;
	x = data->p.x + cos(data->p.rotate_angle) * dist_fb;
	y = data->p.y + sin(data->p.rotate_angle) * dist_fb;
	x += cos(data->p.rotate_angle + (90 * (M_PI / 180))) * dist_lr;
	y += sin(data->p.rotate_angle + (90 * (M_PI / 180))) * dist_lr;
	if (ft_check_walls(data, x, y, 1) == FALSE)
	{
		data->p.x = x;
		data->p.y = y;
	}
	ft_handle_fov(data);
	return (TRUE);
}
