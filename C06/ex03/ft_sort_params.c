/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:11:24 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/19 11:11:46 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	rapp;

	rapp = 0;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && rapp == 0)
	{
		rapp = s1[i] - s2[i];
		i++;
	}
	if (!(s1[i] == '\0' && s2[i] == '\0') && rapp == 0)
		rapp = s1[i] - s2[i];
	return (rapp);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	stampa(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	stampa(argc, argv);
	return (0);
}
