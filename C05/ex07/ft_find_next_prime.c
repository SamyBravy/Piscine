/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:12:39 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/17 14:12:59 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i < nb / 2 && nb % i != 0)
		i++;
	if (nb % i == 0)
		return (0);
	else
		return (1);
}

int	ft_find_next_prime(int nb)
{
	while (nb < 2147483647 && !ft_is_prime(nb))
		nb++;
	return (nb);
}
/*
int	main()
{
	int i = -4;
	
	while (i < 500)
	{
		printf("%d -> %d\n", i, ft_find_next_prime(i));
		i++;
	}
	return 0;
}
*/
