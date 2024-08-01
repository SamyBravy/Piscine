/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:47:21 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/10 10:50:32 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	int	i;
	char	str[] = "cFG9oo";
	
	i = 0;
	ft_strlowcase(str);
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
*/
