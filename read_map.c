#include "so_long.h"

void	map_error(int map, int error, void *mlx)
{
	ft_putstr_fd("Error\n", 2);
	if (error == 1)
		ft_putstr_fd("Map is not rectangular\n", 2);
	else if (error == 2)
		ft_putstr_fd("Map is too small\n", 2);
	else if (error == 3)
		ft_putstr_fd("Map is too big\n", 2);
	close(map);
	if (mlx)
		free(mlx);
	exit(EXIT_FAILURE);
}

void	calculate_map_size(t_data *data, int map, int rd, char buf)
{
	int	first_width;

	first_width = 0;
	while (buf != '\n')
	{
		first_width++;
		rd = read(map, &buf, 1);
	}
	rd = read(map, &buf, 1);
	data->height = 1;
	while (rd != 0)
	{
		data->width = 0;
		while (buf != '\n')
		{
			data->width++;
			rd = read(map, &buf, 1);
		}
		if (data->width != first_width)
			map_error(map, 1, 0);
		data->height++;
		rd = read(map, &buf, 1);
	}
	if (data->height <= 2 || data->width <= 2)
		map_error(map, 2, 0);
}

void	check_map(t_data *data, int map)
{
	int		rd;
	char	buf;
	void	*mlx;
	int		size_x;
	int		size_y;

	rd = read(map, &buf, 1);
	if (rd <= 0)
	{
		if (rd == 0)
			ft_putstr_fd("Error\nThe file is empty\n", 2);
		else
			perror("Read error");
		close(map);
		exit(EXIT_FAILURE);
	}
	calculate_map_size(data, map, rd, buf);
	mlx = mlx_init();
	mlx_get_screen_size(mlx, &size_x, &size_y);
	if (data->width > size_x / 32 || data->height > size_y / 32 - 2)
		map_error(map, 3, mlx);
	free(mlx);
}

void	read_map(int argc, char **argv, t_data *data)
{
	int		len;
	int		map;

	if (argc != 2)
	{
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	map = open(argv[1], O_RDONLY);
	if (map < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp(".ber", argv[1] + len - 4, 4) != 0 || len < 5)
	{
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": Incorrect extension\n", 2);
		close(map);
		exit(EXIT_FAILURE);
	}
	check_map(data, map);
	close(map);
}
