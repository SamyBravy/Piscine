/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:05:50 by sdell-er          #+#    #+#             */
/*   Updated: 2023/10/30 14:05:51 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		j += 1;
	}
	while (nbr > 0)
	{
		ris[i] = nbr % nbase;
		nbr /= nbase;
		i += 1;
	}
	while (--i >= 0)
	{
		ris[i] = base[(int) ris[i]];
		num[j] = ris[i];
		j += 1;
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
			j += 1;
		}
		i += 1;
	}
	return (1);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		nbase;
	char	*num;
	char	*ptr;

	num = malloc(40 * sizeof(char));
	if (!num)
		return (NULL);
	nbase = ft_strlen(base);
	if (!(nbase >= 2 && controllo_base(base, nbase)))
	{
		free(num);
		return (NULL);
	}
	if (nbr < 0)
	{
		num[0] = '-';
		print_conv(-(long long)nbr, nbase, base, &num[1]);
	}
	else
	{
		print_conv(nbr, nbase, base, &num[0]);
	}
	ptr = num;
	return (ptr);
}
