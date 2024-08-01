/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:26:09 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/08 08:33:40 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	*ptr_a;
	int	*ptr_b;

	a = 4;
	b = 5;
	ptr_a = &a;
	ptr_b = &b;
	ft_swap(ptr_a, ptr_b);
	write(1, ptr_a, 1);
	write(1, ptr_b, 1);
	return (0);
}
*/
