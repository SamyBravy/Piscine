/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:44:04 by sdell-er          #+#    #+#             */
/*   Updated: 2023/11/03 14:18:02 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	controllo_base(char *base, int nbase)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbase)
	{
		if (base[i] == '+' || base[i] == '-'
			|| !(base[i] >= 32 && base[i] <= 126))
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	indice_num(char c, int nbase, char *base)
{
	int	i;

	i = 0;
	while (c != base[i] && i < nbase)
		i++;
	return (i);
}

int	conv(char *str, int nbase, char *base)
{
	int	n;
	int	i;
	int	l;
	int	segno;

	l = ft_strlen(str);
	i = 0;
	n = 0;
	segno = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			segno *= -1;
		i++;
	}
	while (indice_num(str[i], nbase, base) != nbase)
	{
		n *= nbase;
		n += indice_num(str[i], nbase, base);
		i++;
	}
	return (n * segno);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbase;

	nbase = ft_strlen(base);
	if (!(nbase >= 2 && controllo_base(base, nbase)))
		return (0);
	return (conv(str, nbase, base));
}
/*
int main()
{
	char str[] = "A0";
	char base[] = "0123456789ABCDEF";
	printf("%d", ft_atoi_base(str, base));
	
	return 0;
}
*/
