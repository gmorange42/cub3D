/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:50:39 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:50:41 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_create_img(t_data *data, t_img *img, int width, int height)
{
	img->img = mlx_new_image(data->mlx, width, height);
	if (!img->img)
		return (ft_put_error("Mlx_new_image failed\n"));
	img->addr = mlx_get_data_addr(img->img, \
			&img->bpp, &img->line_len, &img->endian);
	if (!img->addr)
		return (ft_put_error("Mlx_get_data_addr failed\n"));
	return (TRUE);
}

int	ft_render(t_data *data)
{
	ft_handle_moves(data);
	ft_render_walls(data);
	if (ft_draw_map2d(data) == FALSE)
		return (FALSE);
	if (ft_draw_p(data) == FALSE)
		return (FALSE);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (TRUE);
}

int	ft_display(t_data *data)
{
	if (ft_init_mlx(data) == FALSE)
		return (FALSE);
	if (ft_create_img(data, &data->img, WIDTH, HEIGHT) == FALSE)
		return (FALSE);
	if (ft_import_textures(data) == FALSE)
		return (ft_put_error("Invalid textures\n"));
	ft_spawn_p(data);
	mlx_loop_hook(data->mlx, &ft_render, data);
	mlx_hook(data->win, 2, 1L << 0, &ft_handle_keypress, data);
	mlx_hook(data->win, 3, 1L << 1, &ft_handle_keyrelease, data);
	mlx_hook(data->win, 17, 1L << 17, &ft_handle_cross, data);
	mlx_hook(data->win, 12, 1L << 15, &ft_render, data);
	mlx_loop(data->mlx);
	return (TRUE);
}
