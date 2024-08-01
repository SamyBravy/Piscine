/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:09:15 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/14 09:09:51 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		nb = 0;
	else if (nb == 0)
		nb = 1;
	else if (nb > 1)
		nb *= ft_recursive_factorial(nb - 1);
	return (nb);
}
/*
int	main()
{
	int a = 4;
	
	printf("%d", ft_recursive_factorial(a));
	return (0);
}
*/
