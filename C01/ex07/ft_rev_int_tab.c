/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:32:57 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/08 10:49:23 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		temp = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = temp;
		i++;
	}
}
/*
int	main(void)
{
	int	tab[3];
	int	size;
	int	i;
	char	c;

	tab[0] = 1;
	tab[1] = 3;
	tab[2] = 6;
	size = 3;
	ft_rev_int_tab(tab, size);
	while (i < size)
	{
		c = *(tab + i) + '0';
		write(1, &c, 1);
		i++;
	}
	return (0);
}
*/
