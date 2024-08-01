/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:38:52 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/09 22:39:05 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	int	i;
	char	str[54] = "nuova";
	char	dest[2] = "o";

	ft_strcpy(dest, str);
	i = 0;
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (0);
}
*/
