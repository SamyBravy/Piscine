/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:19:26 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/14 09:19:45 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power == 0)
		nb = 1;
	else if (power < 0)
		nb = 0;
	while (power >= 2)
	{
		nb *= n;
		power--;
	}
	return (nb);
}
/*
int main()
{	
	printf("%d", ft_iterative_power(4, 3));
	return (0);
}
*/
