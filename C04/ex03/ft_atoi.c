/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:15:28 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/13 11:15:51 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	segno;
	int	ris;

	i = 0;
	segno = 1;
	ris = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			segno *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ris *= 10;
		ris += str[i] - '0';
		i++;
	}
	return (ris *= segno);
}
/*
int main()
{
	char str[] = "-7364";
	printf("%d", ft_atoi(str));
	
	return 0;
}
*/
