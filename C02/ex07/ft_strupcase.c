/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:08:11 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/10 10:08:49 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	int	i;
	char	str[89] = "cioi9oo";
	
	i = 0;
	ft_strupcase(str);
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
*/
