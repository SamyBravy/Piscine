/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:56:43 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/20 19:57:00 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		l;
	int		i;
	char	*str;

	l = 0;
	while (src[l] != '\0')
		l++;
	str = malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	char *c = "aaaacs";
	printf("%s", ft_strdup(c));
	return 0;
}
*/
