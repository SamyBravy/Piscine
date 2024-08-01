#include "fileman.h"
#include "userinput.h"
#include <stdio.h>

void print_maps_structure(t_map *my_maps, int count)
{
	int i, j;

	if(!my_maps)
	{
		printf("The array of map structures is NULL.\n");
		return;
	}

	for(i = 0; i < count; i++)
	{
		t_map *my_map = &my_maps[i];

		printf("Map %d:\n", i);
		printf("------\n");
		printf("File Descriptor: %d\n", my_map->fd);
		printf("Bytes Read: %zd\n", my_map->bytesRead); // %zd is the format specifier for ssize_t
		printf("Number of Columns: %d\n", my_map->ncols);
		printf("Number of Rows: %d\n", my_map->nrows);
		printf("Empty Char: %c\n", my_map->empty_char);
		printf("Obstacle: %c\n", my_map->obstacle);
		printf("Full Char: %c\n", my_map->full_char);

		if(!my_map->map)
		{
			printf("The map content is NULL.\n");
			continue;
		}

		printf("Map Content:\n");
		for(j = 0; j < my_map->nrows; j++) // Assuming you have a map with nrows number of rows
		{
			if(my_map->map[j])
				printf("%s\n", my_map->map[j]);
			else
				printf("NULL\n");
		}
		printf("------\n\n");
	}
}


t_map *handle_input(int argc,char **argv)
{
	t_map *my_maps;
	int count;

	if (argc > 1)
	{
		my_maps = read_maps_from_files(argc, argv);
		count = argc - 1; // as maps are from index 1 to argc - 1
	}
	/*
	else // argc == 1
	{
		my_maps = handle_user_input(); // Assuming handle_user_input() creates an array of t_map structures
		count = 1; // Change this value if handle_user_input() creates multiple maps
	}*/
	print_maps_structure(my_maps, count); // Pass the correct count of maps.
	return my_maps;
}
