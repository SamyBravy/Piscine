/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:34:26 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/08 08:49:27 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;
	int	*ptr_div;
	int	*ptr_mod;

	a = 11;
	b = 5;
	ptr_div = &div;
	ptr_mod = &mod;
	ft_div_mod(a, b, ptr_div, ptr_mod);
	write(1, ptr_div, 1);
	write(1, ptr_mod, 1);
	return (0);
}
*/
