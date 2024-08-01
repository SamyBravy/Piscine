/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:40:34 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/09 20:40:44 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_if01(int i, int j, int x, int y)
{
	if (j == 0 && i == 0)
	{
		ft_putchar('/');
	}
	else if ((j == x - 1 && i == 0) || (j == 0 && i == y - 1))
	{
		ft_putchar(92);
	}
	else if (j == x - 1 && i == y - 1)
	{
		ft_putchar('/');
	}
	else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
	{
		ft_putchar('*');
	}
	else
	{
		ft_putchar(' ');
	}
}

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

void	ft_if03(int i, int j, int x, int y)
{
	if (j == 0 && i == 0)
	{
		ft_putchar('A');
	}
	else if (j == x - 1 && i == 0)
	{
		ft_putchar('C');
	}
	else if (j == 0 && i == y - 1)
	{
		ft_putchar('A');
	}
	else if (j == x - 1 && i == y - 1)
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

void	ft_if04(int i, int j, int x, int y)
{
	if (j == 0 && i == 0)
	{
		ft_putchar('A');
	}
	else if ((j == x - 1 && i == 0) || (j == 0 && i == y - 1))
	{
		ft_putchar('C');
	}
	else if (j == x - 1 && i == y - 1)
	{
		ft_putchar('A');
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
	int		i;
	int		j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_if04(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(void)
{
	rush(11, 13);
	return (0);
}
