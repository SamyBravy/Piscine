/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:59:43 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/14 09:00:03 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	n;

	n = nb;
	if (nb < 0)
		nb = 0;
	else if (nb == 0)
		nb = 1;
	while (n > 1)
		nb *= --n;
	return (nb);
}
/*
int	main()
{
	int a = 4;
	
	printf("%d", ft_iterative_factorial(a));
	return (0);
}
*/
