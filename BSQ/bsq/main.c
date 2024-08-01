#include "handleinput.h"
#include "fileman.h"
#include "solve.h"


int	main(int argc,char **argv)
{
	t_map	*my_maps;

	my_maps = handle_input(argc, argv);
	if (my_maps != NULL)
		return (1);
	return (0);
	//solve_array_of_maps(my_maps, argc - 1);
	print_maps_structure(my_maps, argc - 1);
}
