#include "fileman.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void	display_error(char *message)
{
	write(2, message, ft_strlen(message));
}

char *read_line(int fd, ssize_t *bytesRead)
{
	char c;
	char *line;
	int i;

	line = malloc(1024);
	if (!line) return (NULL);
	i = 0;
	while ((*bytesRead = read(fd, &c, 1)) > 0 && c != '\n' && i < 1023)
		line[i++] = c;
	line[i] = '\0';
	return (line);
}

int init_metadata(t_map *my_map, char *line)
{
    if (!line)
        return (0);

    int i = 0;
    my_map->nrows = 0;
    // Reading digits and converting them to an integer
    while (line[i] >= '0' && line[i] <= '9')
    {
        my_map->nrows = my_map->nrows * 10 + (line[i] - '0');
        i++;
    }

    // Now, i should be pointing to the first character after the number.
    if (line[i] == '\0' || line[i + 1] == '\0' || line[i + 2] == '\0')
        return (0); // Not enough characters for the metadata

    my_map->empty_char = line[i];
    my_map->obstacle = line[i + 1];
    my_map->full_char = line[i + 2];

    if (!(my_map->map = malloc(sizeof(char *) * my_map->nrows)))
        return (0);

    return (1);
}

int process_line(t_map *my_map, char *line, int line_count) {
	if (line_count == 0) {
		my_map->ncols = ft_strlen(line);
	}

	if(line_count >= my_map->nrows) return 0;
	my_map->map[line_count] = ft_strdup(line);

	return my_map->map[line_count] != NULL;
}

void cleanup_my_map(t_map *my_map)
{
	if(my_map->map)
	{
		for(int i = 0; i < my_map->nrows; i++)
			if(my_map->map[i]) free(my_map->map[i]);

		free(my_map->map);
	}
}



int	ft_read_file(t_map *my_map, char *filename)
{
    char *line;
    my_map->fd = open(filename, O_RDONLY);
    if (my_map->fd == -1)
        return (0);

    // Reading and initializing metadata
    line = read_line(my_map->fd, &my_map->bytesRead);
    if (!line || !init_metadata(my_map, line)) {
        free(line);
        close(my_map->fd);
        return (0);
    }
    free(line); // Freeing line after initializing metadata

    int line_count = 0;
    while ((line = read_line(my_map->fd, &my_map->bytesRead)) && my_map->bytesRead > 0)
    {
        if(!process_line(my_map, line, line_count)) {
            free(line);
            close(my_map->fd);
            return (0); // If processing line fails
        }
        free(line);
        line_count++;
    }

    close(my_map->fd);
    return (my_map->bytesRead != -1);
}

t_map *load_map_into_structure(char *filename, t_map *my_map)
{
	// Removed the call to init_metadata here
	if (!ft_read_file(my_map, filename))
	{
		display_error("Error: Unable to read content from file\n");
		return (NULL);
	}

	return my_map;
}


void	cleanup_maps(t_map *maps, int count)
{
	for (int i = 0; i < count; i++)
	{
		cleanup_my_map(&maps[i]);
	}
	free(maps);
}

t_map *read_maps_from_files(int argc, char **argv)
{
	int i;
	t_map *maps;
	maps = malloc(sizeof(t_map) * (argc - 1));
	if (!maps)
		return (write(2, "Failed to allocate memory for maps\n", 36), NULL);

	for(i = 1; i < argc; i++) // i starts from 1 to exclude the executable name
	{
		if (!load_map_into_structure(argv[i], &maps[i - 1]))
		{
			write(2, "Failed to load map from file: ", 30);
			write(2, argv[i], ft_strlen(argv[i]));
			write(2, "\n", 1);
			cleanup_maps(maps, i - 1);
			return (NULL);
		}
	}
	return (maps);
}
