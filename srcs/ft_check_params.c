/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:50:34 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:50:35 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_file(char *file, t_data *data)
{
	char	buf[2];

	data->fd = open(file, O_RDONLY);
	if (data->fd == -1)
	{
		ft_error_open(strerror(errno));
		return (FALSE);
	}
	else if (read(data->fd, buf, 0) == -1)
	{
		ft_put_error("Invalid file\n");
		return (FALSE);
	}
	return (TRUE);
}

int	ft_check_params(int argc, char **argv, t_data *data)
{
	int	len;

	if (argc != 2)
	{
		ft_put_error("Usage: ./cub3D map.cub\n");
		return (FALSE);
	}
	len = ft_strlen(argv[1]) - 4;
	if (ft_strlen(argv[1]) >= 4 && \
			ft_strncmp(&argv[1][len], ".cub", -1) == TRUE)
	{
		if (ft_check_file(argv[1], data) == FALSE)
			return (FALSE);
	}
	else
	{
		ft_put_error("Invalid file extension\n");
		return (FALSE);
	}
	return (TRUE);
}
