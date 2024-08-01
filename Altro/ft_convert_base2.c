/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:28:43 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/26 16:28:46 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

void	print_conv(long long nbr, int nbase, char *base, char *num)
{
	int		i;
	int		j;
	char	ris[150];

	i = 0;
	j = 0;
	if (nbr == 0)
	{
		num[0] = base[0];
		j++;
	}
	while (nbr > 0)
	{
		ris[i] = nbr % nbase;
		nbr /= nbase;
		i++;
	}
	while (--i >= 0)
	{
		ris[i] = base[(int) ris[i]];
		num[j] = ris[i];
		j++;
	}
	num[j] = '\0';
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

char	*ft_putnbr_base(int nbr, char *base)
{
	int		nbase;
	char	num[40];
	char	*ptr;

	nbase = ft_strlen(base);
	if (nbr < 0)
	{
		num[0] = '-';
		print_conv(-(long long)nbr, nbase, base, &num[1]);
	}
	else
	{
		print_conv(nbr, nbase, base, &num[0]);
		ptr = &num[0];
	}
	return (ptr);
}
