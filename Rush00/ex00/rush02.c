/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:20:39 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/09 22:21:23 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_if02(int i, int j, int x, int y)
{
	if ((j == 0 && i == 0) || (j == x - 1 && i == 0))
	{
		ft_putchar('A');
	}
	else if ((j == 0 && i == y - 1) || (j == x - 1 && i == y - 1))
	{
		ft_putchar('C');
	}
	else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y && x > 0)
	{
		j = 0;
		while (j < x)
		{
			ft_if02(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}