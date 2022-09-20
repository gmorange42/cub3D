/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:49:58 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:50:00 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || \
				str[i] == '\v' || str[i] == '\f')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_check_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_check_chars(char *str, char *chars)
{
	int	i;
	int	j;
	int	occur;

	i = 0;
	while (str && str[i])
	{
		occur = FALSE;
		j = 0;
		while (chars && chars[j])
		{
			if (str[i] == chars[j])
				occur = TRUE;
			j++;
		}
		if (occur == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
