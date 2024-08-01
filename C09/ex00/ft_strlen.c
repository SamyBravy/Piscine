/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:12:47 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/08 09:28:02 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	*str;
	char	n;

	str = "cacca";
	n = ft_strlen(str) + '0';
	write(1, &n, 1);
	return (0);
}
*/
