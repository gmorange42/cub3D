/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:53 by echuong           #+#    #+#             */
/*   Updated: 2022/03/17 13:55:31 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->t[i].img = NULL;
		data->t[i].addr = NULL;
		i++;
	}
}

void	ft_init_rays(t_ray rays[WIDTH])
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		rays[i].up = 0;
		rays[i].down = 0;
		rays[i].left = 0;
		rays[i].right = 0;
		rays[i].h_x = 0;
		rays[i].h_y = 0;
		rays[i].v_x = 0;
		rays[i].v_y = 0;
		rays[i].found_h = 0;
		rays[i].found_v = 0;
		rays[i].dist_h = 0;
		rays[i].dist_v = 0;
		rays[i].x = 0;
		rays[i].y = 0;
		rays[i].len = 0;
		rays[i].text_x = 0;
		rays[i].text_y = 0;
		i++;
	}
}

void	ft_init_tab(int f[4], int c[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		f[i] = 0;
		c[i] = 0;
		i++;
	}
}

t_p	ft_init_p(void)
{
	t_p	p;

	p.fov = FOV * (M_PI / 180);
	p.x = 0;
	p.y = 0;
	p.dir = 0;
	p.turn = 0;
	p.front_back = 0;
	p.left_right = 0;
	p.rotate_angle = 0;
	p.move_speed = 0.15;
	p.rotate_speed = p.move_speed * 14 * (M_PI / 180);
	return (p);
}

t_data	ft_init_data(void)
{
	t_data	data;

	data.fd = 0;
	data.line = NULL;
	data.tmp = NULL;
	data.n = NULL;
	data.s = NULL;
	data.w = NULL;
	data.e = NULL;
	data.line_len = 0;
	data.nb_line = 0;
	data.map = NULL;
	data.p = ft_init_p();
	data.mlx = NULL;
	data.win = NULL;
	data.dist_pp = (WIDTH / 2) / tan(data.p.fov / 2);
	ft_init_tab(data.f, data.c);
	ft_init_rays(data.rays);
	ft_init_textures(&data);
	return (data);
}
