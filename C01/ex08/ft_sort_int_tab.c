/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:09:01 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/09 14:09:35 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		k = 0;
		while (k < size - 1 - i)
		{
			if (tab[k] > tab[k + 1])
			{
				temp = tab[k];
				tab[k] = tab[k + 1];
				tab[k + 1] = temp;
			}
			k++;
		}
		i++;
	}
}
/*
int	main(void)
{
	int	arr[6];
	int	i;
	char	c;

	i = 0;
	while (i < 6)
	{
		arr[i] = 7 - i;
		i++;
	}
	ft_sort_int_tab(&arr[0], 6);
	i = 0;
	while (i < 6)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	return (0);
}
*/
