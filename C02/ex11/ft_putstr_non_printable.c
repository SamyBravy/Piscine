/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:11:05 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/11 09:11:29 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_conv(char c)
{
	int		i;
	int		c2;
	char	ris[3];
	char	e;

	c2 = c;
	if (c2 < 0)
		c2 += 256;
	if (c2 <= 15)
		write(1, "0", 1);
	i = 0;
	while (c2 > 0)
	{
		ris[i] = c2 % 16;
		c2 /= 16;
		i++;
	}
	while (--i >= 0)
	{
		if (ris[i] <= 9)
			e = ris[i] + '0';
		else
			e = ris[i] % 10 + 'a';
		write(1, &e, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	c = 92;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, &c, 1);
			print_conv(str[i]);
		}
		i++;
	}
}
/*
int	main(void)
{
	int	i;
	char	str[] = "Coucou\ntu vas bien ?";

    	str[2] = 181;	
	ft_putstr_non_printable(str);
	return (0);
}
*/
