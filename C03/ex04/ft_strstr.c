/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:40:13 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/12 19:40:41 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	l;

	l = 0;
	while (to_find[l])
		l++;
	i = 0;
	j = 0;
	while (str[i] && j < l)
	{
		if (str[i] == to_find[j])
			j++;
		else if (str[i] == to_find[0])
			j = 1;
		else
			j = 0;
		i++;
	}
	if (j == l)
		return (&str[i - j]);
	else
		return (NULL);
}
/*
int	main(void)
{
	char s1[100] = "C'era una volta ";
	char s2[] = "volta";
	
	printf(" %s ", ft_strstr(s1, s2));
	return 0;
}
*/
