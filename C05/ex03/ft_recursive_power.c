/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:30:33 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/14 09:30:55 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power >= 2)
		nb *= ft_recursive_power(nb, power - 1);
	else if (power == 0)
		nb = 1;
	else if (power < 0)
		nb = 0;
	return (nb);
}
/*
int main()
{	
	printf("%d", ft_recursive_power(4, 3));
	return (0);
}
*/
