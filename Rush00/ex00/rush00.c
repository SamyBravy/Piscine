/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:15:33 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/09 22:18:55 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_if00(int i, int j, int x, int y)
{
	if ((i == 0 && (j == x - 1 || j == 0)) 
		|| ((i == y - 1) && (j == x - 1 || j == 0)))
	{
		ft_putchar('o');
	}
	else if (i == 0 || i == y - 1)
	{
		ft_putchar('-');
	}
	else if (j == 0 || j == x - 1)
	{
		ft_putchar('|');
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
			ft_if00(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
