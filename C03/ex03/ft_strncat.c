/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:29:57 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/15 11:30:07 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	l;
	unsigned int	i;

	i = 0;
	l = 0;
	while (dest[l])
		l++;
	while (src[i] && i < nb)
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
	char dest1[100] = "C'era una volta ";
	char src1[] = "Cecco Rivolta";
	
	printf("%s\n", ft_strncat(s1, s2, 5));
	printf("%s", strncat(dest1, src1, 5));
	return 0;
}
*/
