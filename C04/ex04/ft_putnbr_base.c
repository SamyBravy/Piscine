/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:51:01 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/15 17:51:56 by sdell-er         ###   ########.fr       */
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

void	print_conv(long long nbr, int nbase, char *base)
{
	int		i;
	char	ris[150];

	i = 0;
	if (nbr == 0)
		write(1, &base[0], 1);
	while (nbr > 0)
	{
		ris[i] = nbr % nbase;
		nbr /= nbase;
		i++;
	}
	while (--i >= 0)
	{
		ris[i] = base[(int) ris[i]];
		write(1, &ris[i], 1);
	}
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	nbase;

	nbase = ft_strlen(base);
	if (!(nbase >= 2 && controllo_base(base, nbase)))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_conv(-(long long)nbr, nbase, base);
	}
	else
		print_conv(nbr, nbase, base);
}
/*
int	main()
{
	int	num = 356;
	char	base[] = "01234567";
	
	ft_putnbr_base(num, base);
	
	return 0;
}
*/
