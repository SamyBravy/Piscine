#ifndef FILEMAN_H
#define FILEMAN_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct  s_map
{
    int         fd;
    ssize_t     bytesRead;
    char        **map;
    int         ncols;
    int         nrows;
    char        empty_char;
    char        obstacle;
    char        full_char;

}t_map;

char    *read_line(int fd, ssize_t *bytesRead);

int init_metadata(t_map *my_map, char *line);

int     process_line(t_map *my_map, char *line, int line_count);

void cleanup_my_map(t_map *my_map);

int	ft_read_file(t_map *my_map, char *filename);

t_map   *load_map_into_structure(char *filename, t_map *my_map);

void cleanup_maps(t_map *maps, int count);

t_map *read_maps_from_files(int argc, char **argv);

#endif
