#include "fileman.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:52:18 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/28 12:48:59 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fileman.h"
/*
typedef struct s_map
{
    char        **map;
    int         nrows;
    int	ncols;
    char        empty_char;
    char        obstacle;
    char        full_char;
}t_map;

*/
int	check_map(t_map *my_map)
{
	int	i;
	int	j;

	if (my_map->nrows < 1 || my_map->ncols < 1)
		return (0);
	if (my_map->empty_char == my_map->obstacle
		|| my_map->empty_char == my_map->full_char
		|| my_map->full_char == my_map->obstacle)
		return (0);
	i = 0;
	while (i < my_map->nrows)
	{
		j = 0;
		while (my_map->map[i][j])
		{
			if (my_map->map[i][j] != my_map->empty_char && my_map->map[i][j]
				!= my_map->obstacle && my_map->map[i][j] != my_map->full_char)
				return (0);
			j++;
		}
		if (j != my_map->ncols)
			return (0);
		i++;
	}
	return (1);
}

int	ch_obs(t_map *my_map, int i, int l, int k)
{
	if (my_map->map[i / l + k / my_map->nrows]
		[i % l + k % my_map->ncols] == my_map->obstacle)
		return (1);
	return (0);
}

int	ch_while(int l, int k, t_map *my_map)
{
	if ((++l - 1 + k / my_map->nrows == my_map->nrows
			|| l - 1 + k % my_map->ncols == my_map->ncols))
		return (1);
	return (0);
}

void	solve_map(t_map *my_map)
{
	int	k;
	int	l;
	int	i;
	int	obs;
	int	*kdim;

	kdim = malloc((my_map->nrows * my_map->ncols) * sizeof(int));
	k = 0;
	while (k < my_map->nrows * my_map->ncols)
	{
		l = 0;
		obs = 0;
		while (!obs && !ch_while(l, k, &my_map))
		{
			i = -1;
			while (++i < l * l - 1 && !obs)
			{
				if (ch_obs(&my_map, i, l, k))
					obs = 1;
			}
		}
		kdim[k++] = l - 2;
	}
	i = 0;
	while (--k >= 0)
	{
		if (kdim[k] >= kdim[i])
			i = k;
	}
	k = i;
	l = kdim[i];
	i = -1;
	while (++i < l * l)
		my_map->map[i / l + k / my_map->nrows]
		[i % l + k % my_map->ncols] = my_map->full_char;
	if (l < 1)
		my_map->map = NULL;
	free(kdim);
}
/*
void	ft_print(t_map *my_map)
{
	int	k = 0;

	while (k < my_map->nrows * my_map->ncols)
	{
		write(1, &my_map->map[k / my_map->nrows][k % my_map->ncols], 1);
		if (k % my_map->ncols == my_map->ncols - 1)
			write(1, "\n", 1);
		k++;
	}
}
*/

void	solve_array_of_maps(t_map *my_maps, int n_maps)
{
	int	i;

	i = 0;
	while (i < n_maps)
	{
		if (check_map(&my_maps[i]))
			solve_map(&my_maps[i]);
		else
			my_maps[i].map = NULL;
		/*ft_print(&my_maps[i]);*/
		i++;
	}
}
/*
int	main()
{
	t_map my_maps[1];

	char *pippo[] = 	 	 {"...",
					  "...",
					  "...",
					  "...",
					  "...",
					  "...",
					  "...",
					  "...",
					  "..o"};
	char **mat = malloc (sizeof(char*) * 9);

	for (int i = 0; i < 9; i++)
	{
		mat[i] = malloc (sizeof(char) * 4);
		for (int j = 0; j < 3; j++){
			mat[i][j] = pippo[i][j];
		}
	}

	my_maps[0].map = mat;
	my_maps[0].nrows = 9;
	my_maps[0].ncols = 3;
	my_maps[0].empty_char = '.';
	my_maps[0].obstacle = 'o';
	my_maps[0].full_char = 'x';
	solve_array_of_maps(my_maps, 1);
	return (0);
}*/
