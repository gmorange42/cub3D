/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:55:38 by echuong           #+#    #+#             */
/*   Updated: 2022/03/17 11:33:00 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 0;
	data = ft_init_data();
	if (ft_check_params(argc, argv, &data) == FALSE || \
		ft_parse_file(&data) == FALSE || \
		ft_display(&data) == FALSE)
	{
		ft_free(&data);
		return (1);
	}
	ft_free(&data);
	return (0);
}
