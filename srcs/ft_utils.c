/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echuong <echuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:55:32 by echuong           #+#    #+#             */
/*   Updated: 2022/03/16 16:55:33 by echuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n >= 0)
	{
		while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i] && i + 1 < n)
			i++;
	}
	else
	{
		while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
			i++;
	}
	if (s1[i] != s2[i])
		return (FALSE);
	return (TRUE);
}

char	*ft_strdup(t_data *data, char *str, int len, int flag)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!str)
		return (NULL);
	if (len < 0)
		len = ft_strlen(str);
	cpy = malloc(sizeof(char) * (len + 1));
	ft_check_malloc(data, cpy);
	if (!cpy)
		return (NULL);
	while (str && str[i] && i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	if (flag == TRUE && str)
		free(str);
	return (cpy);
}

char	*ft_strjoin(t_data *data, char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*cpy;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	cpy = malloc(sizeof(char) * (len + 1));
	ft_check_malloc(data, cpy);
	while (s1 && s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		cpy[i++] = s2[j++];
	cpy[i] = '\0';
	if (s1)
		free(s1);
	return (cpy);
}

int	ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str && str[i] && ft_isdigit(str[i]) == TRUE)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}
