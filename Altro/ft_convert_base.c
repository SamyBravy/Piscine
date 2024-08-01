/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:28:32 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/26 16:28:33 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_putnbr_base(int nbr, char *base);
int		ft_strlen(char *str);
int		controllo_base(char *base, int nbase);

int	ft_numlen(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
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
	int	segno;

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
	return (conv(str, nbase, base));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n1;

	if (!controllo_base(base_from, ft_strlen(base_from))
		|| !controllo_base(base_to, ft_strlen(base_to))
		|| ft_strlen(base_from) < 2 || ft_strlen(base_to) < 2)
		return (NULL);
	n1 = ft_atoi_base(nbr, base_from);
	nbr = malloc((ft_numlen(n1) + 1) * sizeof(char));
	nbr = ft_putnbr_base(n1, base_to);
	return (nbr);
}
/*
int	main()
{
	char *nbr = "0";
	char *base_from = "0123456789";
	char *base_to = "ty";
	nbr = ft_convert_base(nbr, base_from, base_to);
	int i = 0;
	while (nbr && nbr[i]) 
	{
		write(1, &nbr[i], 1);
		i += 1;
	}
	return 0;
	
}*/
