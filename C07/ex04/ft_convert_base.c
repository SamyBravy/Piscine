/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:05:39 by sdell-er          #+#    #+#             */
/*   Updated: 2023/11/03 14:21:32 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_numlen(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num /= 10;
		i += 1;
	}
	return (i);
}

int	indice_num(char c, int nbase, char *base)
{
	int	i;

	i = 0;
	while (c != base[i] && i < nbase)
		i += 1;
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
		i += 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			segno *= -1;
		i += 1;
	}
	while (indice_num(str[i], nbase, base) != nbase)
	{
		n *= nbase;
		n += indice_num(str[i], nbase, base);
		i += 1;
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
	int		n1;
	char	*new_nbr;

	if (!controllo_base(base_from, ft_strlen(base_from))
		|| !controllo_base(base_to, ft_strlen(base_to))
		|| ft_strlen(base_from) < 2 || ft_strlen(base_to) < 2)
		return (NULL);
	n1 = ft_atoi_base(nbr, base_from);
	new_nbr = ft_putnbr_base(n1, base_to);
	return (new_nbr);
}

/*int	main()
{
	char *nbr = "10";
	char *base_from = "0123456789";
	char *base_to = "01";
	nbr = ft_convert_base(nbr, base_from, base_to);
	int i = 0;
	while (nbr && nbr[i]) 
	{
		write(1, &nbr[i], 1);
		i += 1;
	}
	return 0;
}*/
