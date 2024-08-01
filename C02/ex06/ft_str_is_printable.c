/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:57:15 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/10 09:57:38 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	ris;
	int	i;

	ris = 1;
	i = 0;
	while (str[i] != '\0' && ris == 1)
	{
		if (!(str[i] <= 126 && str[i] >= 32))
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
	printf(" %d ", ft_str_is_printable(str));
	return (0);
}
*/
