/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:54:33 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:54:34 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_free(data);
		exit(0);
	}
	if (keysym == 'w')
		data->p.front_back = 1;
	if (keysym == 's')
		data->p.front_back = -1;
	if (keysym == 'a')
		data->p.left_right = -1;
	if (keysym == 'd')
		data->p.left_right = 1;
	if (keysym == 65361)
		data->p.turn = -1;
	if (keysym == 65363)
		data->p.turn = 1;
	return (TRUE);
}

int	ft_handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == 'w')
		data->p.front_back = 0;
	if (keysym == 's')
		data->p.front_back = 0;
	if (keysym == 'a')
		data->p.left_right = 0;
	if (keysym == 'd')
		data->p.left_right = 0;
	if (keysym == 65361)
		data->p.turn = 0;
	if (keysym == 65363)
		data->p.turn = 0;
	return (TRUE);
}

int	ft_handle_cross(t_data *data)
{
	ft_free(data);
	exit (0);
}
