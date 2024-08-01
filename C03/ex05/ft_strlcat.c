/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:25:09 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/15 11:25:24 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	l2;

	i = 0;
	l = 0;
	l2 = 0;
	while (dest[l])
		l++;
	while (src[l2])
		l2++;
	if (size == 0)
		return (l2);
	while (src[i] && i + l < size - 1)
	{
		dest[i + l] = src[i];
		i++;
	}
	if (i < size)
		dest[i + l] = '\0';
	if (l > size)
		return (l2 + size);
	return (l + l2);
}
/*
int	main(void)
{
	char s1[18] = "C'era una volta ";
	char s2[] = "Co";
	
	printf("\n%d  %s", ft_strlcat(s1, s2, 18), s1);
	return 0;
}
*/
