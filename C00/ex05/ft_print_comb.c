/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:07:28 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/07 21:15:52 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_c3_cycle(char c1, char c2, char c3)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	if (c1 != '7' || c2 != '8' || c3 != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '7')
	{
		c2 = c1 + 1;
		while (c2 <= '8')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				print_c3_cycle(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
