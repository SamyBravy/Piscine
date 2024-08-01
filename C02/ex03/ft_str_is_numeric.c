/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:47:39 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/10 09:48:04 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	ris;
	int	i;

	ris = 1;
	i = 0;
	while (str[i] != '\0' && ris == 1)
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			ris = 0;
		i++;
	}
	return (ris);
}
/*
int	main(void)
{
	char	*str;
	
	str = "cioi9oo";
	printf(" %d ", ft_str_is_numeric(str));
	return (0);
}
*/
