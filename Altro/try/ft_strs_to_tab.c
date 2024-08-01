/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:06:16 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/26 14:06:18 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	int		l;
	int		i;
	char	*str;

	l = 0;
	while (src[l] != '\0')
		l++;
	str = malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;
	arr = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = NULL;
	return (arr);
}
