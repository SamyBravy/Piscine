/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:42:02 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/14 09:42:29 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fibonacci(int index)
{
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index >= 2)
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	return (-1);
}
/*
int	main()
{
	int i = 0;
	while(i < 15)
			printf("%d\n", ft_fibonacci(i++));
	return 0;
}
*/
