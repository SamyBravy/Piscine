/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:26:13 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/12 09:26:36 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	l;
	int	i;

	i = 0;
	l = 0;
	while (dest[l])
		l++;
	while (src[i])
	{
		dest[l + i] = src[i];
		i++;
	}
	dest[l + i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char s1[100] = "C'era una volta ";
	char s2[] = "Cecco Rivolta";
	
	printf(" %s ", ft_strcat(s1, s2));
	return 0;
}
*/
