/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:50:14 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/10 11:50:56 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	int	l;
	int	size2;

	size2 = size;
	i = 0;
	l = 0;
	while (src[l])
		l++;
	while (src[i] != '\0' && i < size2 - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (l);
}
/*
int	main(void)
{
	int	i;
	char	str1[] = "gdf";
	char	str2[] = "SFaaagbdfsdf";
	
	i = 0;
	ft_strlcpy(str1, str2, 4);
	while(str1[i])
	{
		write(1, &str1[i], 1);
		i++;
	}
	return (0);
}
*/
