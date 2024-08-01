/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:50:12 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/08 08:56:43 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a /= *b;
	*b = c % *b;
}
/*
int	main(void)
{
	int     a;
	int     b;
	int     *ptr_div;
	int     *ptr_mod;

	a = 11;
	b = 5;
	ptr_div = &a;
	ptr_mod = &b;
	ft_ultimate_div_mod(ptr_div, ptr_mod);
	printf("%d %d", a, b);
	return (0);
}
*/
