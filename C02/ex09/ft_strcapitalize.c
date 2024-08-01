/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:52:56 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/10 10:54:31 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	max;
	int	i;

	max = 1;
	i = 0;
	while (str[i])
	{
		if ((str[i] <= 'Z' && str[i] >= 'A') || (str[i] <= 'z' && str[i] >= 'a')
			|| (str[i] <= '9' && str[i] >= '0'))
		{
			if (max == 1 && str[i] <= 'z' && str[i] >= 'a')
				str[i] -= 32;
			else if (max == 0 && str[i] <= 'Z' && str[i] >= 'A')
				str[i] += 32;
			max = 0;
		}
		else
			max = 1;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	int	i;
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";;
	
	i = 0;
	ft_strcapitalize(str);
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
*/
