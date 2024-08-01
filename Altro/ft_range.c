/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:00:08 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/21 00:00:31 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min < max)
	{
		arr = malloc((max - min) * sizeof(int));
		if (arr == NULL)
			return (NULL);
	}
	else
		arr = NULL;
	i = 0;
	while (i < max - min)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
int main()
{
	int *arr = ft_range(3, 7);
	int i = 0;
	while(i < 7 - 3)
	{
		printf("%d", arr[i]);
		i++;
	}
	return 0;
}
*/
