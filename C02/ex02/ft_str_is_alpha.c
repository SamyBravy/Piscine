/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:37:13 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/10 09:37:34 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	ris;
	int	i;

	ris = 1;
	i = 0;
	while (str[i] != '\0' && ris == 1)
	{
		if (!((str[i] <= 'Z' && str[i] >= 'A')
				|| (str[i] <= 'z' && str[i] >= 'a')))
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
	printf(" %d ", ft_str_is_alpha(str));
	return (0);
}
*/
