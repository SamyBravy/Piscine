#include "fileman.h"
#include "string.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int fill_map(t_map *my_map)
{
	if (!my_map || my_map->nrows <= 0)
		return 0;

	int i = 0;
	char *line;


	my_map->map = malloc(sizeof(char *) * my_map->nrows);
	if (!my_map->map)
		return 0;

	while (i < my_map->nrows)
	{

		line = read_line(STDIN_FILENO, &my_map->bytesRead);
		if (!line)
		{

			for(int j = 0; j < i; j++)
				free(my_map->map[j]);
			free(my_map->map);
			return 0;
		}



		my_map->map[i] = line;
		i++;
	}

	return 1;
}


int allocate_map(t_map *my_map)
{
	if (!my_map || my_map->nrows <= 0 || my_map->ncols <= 0) return 0;

	my_map->map = malloc(my_map->nrows * sizeof(char *));
	if (!my_map->map) return 0;

	for(int i = 0; i < my_map->nrows; i++)
	{
		my_map->map[i] = malloc((my_map->ncols + 1) * sizeof(char));
		if(!my_map->map[i])
		{
			for(int j = 0; j < i; j++)
				free(my_map->map[j]);
			free(my_map->map);
			return 0;
		}
	}
	return 1;
}

t_map *handle_user_input(void)
{
	int	i;

	i = 0;
	t_map *my_map = malloc(sizeof(t_map));
	if (!my_map) return NULL;

	if (scanf("%d.%c%c%c", &my_map->nrows, &my_map->empty_char, &my_map->obstacle, &my_map->full_char) != 4)
	{
		free(my_map);
		return NULL;
	}


		if (scanf("%s", my_map->map[i]) != 1)
	{
	cleanup_my_map(my_map);
	free(my_map);
	return NULL;
	}
	my_map->ncols = ft_strlen(my_map->map[i]);
	i++;
	while (i < my_map->nrows)
	{
		if (scanf("%s", my_map->map[i]) != 1)
		{
			cleanup_my_map(my_map);
					free(my_map);
					return NULL;
				}
		}


	if (!allocate_map(my_map))
	{
		cleanup_my_map(my_map);
		free(my_map);
		return NULL;
	}

	if(!fill_map(my_map))
	{
		cleanup_my_map(my_map);
		free(my_map);
		return NULL;
	}


	return my_map;
}
