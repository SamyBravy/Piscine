/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:38:03 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/07 21:26:05 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	arr_cycle(char *arr)
{
	while (*(arr + 2) <= '9')
	{
		while (*(arr + 3) <= '9')
		{
			write(1, arr, 1);
			write(1, (arr + 1), 1);
			write(1, " ", 1);
			write(1, (arr + 2), 1);
			write(1, (arr + 3), 1);
			if (*arr != '9' || *(arr + 1) != '8')
				write(1, ", ", 2);
			*(arr + 3) = *(arr + 3) + 1;
		}
		*(arr + 3) = '0';
		*(arr + 2) = *(arr + 2) + 1;
	}
	++*(arr + 1);
}

void	ft_print_comb2(void)
{
	char	arr[4];

	arr[0] = '0';
	while (arr[0] <= '9')
	{
		arr[1] = '0';
		while (arr[1] <= '9')
		{
			if (arr[1] != '9')
			{
				arr[3] = arr[1] + 1;
				arr[2] = arr[0];
			}
			else
			{
				arr[3] = '0';
				arr[2] = arr[0] + 1;
			}
			arr_cycle(&arr[0]);
		}
		arr[0]++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
