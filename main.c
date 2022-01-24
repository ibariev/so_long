#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	data;

	read_map(argc, argv, &data);
	create_array(&data, argv);
	parse_map(&data);
	create_initial_image(&data, &mlx);
	process_events(&data, &mlx);
}
