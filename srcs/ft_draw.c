/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:50:46 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:50:49 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pxl_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	ft_draw_rect(t_data *data, t_img *img, t_rect rect, int color)
{
	int	i;
	int	j;

	if (!data->win)
	{
		ft_put_error("Error with window\n");
		return (FALSE);
	}
	j = rect.y;
	while (j < rect.y + rect.height)
	{
		i = rect.x;
		while (i < rect.x + rect.width)
		{
			ft_pxl_put(img, i, j, color);
			i++;
		}
		j++;
	}
	return (TRUE);
}
