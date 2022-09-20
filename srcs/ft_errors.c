/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:50:53 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:50:54 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_malloc(t_data *data, void *elem)
{
	char	*str;

	str = "Error\nMalloc failed\n";
	if (!elem)
	{
		write(2, str, ft_strlen(str));
		ft_free(data);
	}
}

void	ft_error_open(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	ft_put_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	return (FALSE);
}
