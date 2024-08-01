/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 07:47:57 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/08 07:56:48 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	str[11];
	int		i;

	str[10] = '\0';
	i = 0;
	if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		while (nb > 0)
		{
			str[i++] = (nb % 10) + '0';
			nb /= 10;
		}
		while (i--)
			write(1, &str[i], 1);
	}
}
/*
int	main(void)
{
	int	n;

	n = 449;
	ft_putnbr(n);
	return (0);
}
*/
