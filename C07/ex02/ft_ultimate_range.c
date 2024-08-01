/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:06:47 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/21 00:07:48 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;

	if (min < max)
	{
		arr = malloc((max - min) * sizeof(int));
		if (arr == NULL)
			return (-1);
	}
	else
	{
		range = NULL;
		return (0);
	}
	i = 0;
	while (i < max - min)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (max - min);
}
/*
int main()
{
	int **arr;
	int i = 0;
	arr = malloc((2) * sizeof(int *));
	arr[0] = malloc(9 * sizeof(int));
	arr[1] = malloc(45 * sizeof(int));
	printf("%d\n", ft_ultimate_range(arr, 3, 7));
	while(i < 7 - 3)
	{
		printf("%d ", arr[0][i]);
		i++;
	}
	return 0;
}
*/
