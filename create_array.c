#include "so_long.h"

void	malloc_array(t_data *data)
{
	int	y;
	int	i;

	data->map = malloc(data->height * sizeof(*(data->map)));
	if (data->map == NULL)
	{
		ft_putstr_fd("Malloc error\n", 2);
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (y < data->height)
	{
		data->map[y] = malloc(data->width * sizeof(**(data->map)));
		if (data->map[y] == NULL)
		{
			i = -1;
			while (++i < y)
				free(data->map[i]);
			free(data->map);
			ft_putstr_fd("Malloc error\n", 2);
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

void	write_in_array(t_data *data, char **argv)
{
	char	ch;
	int		map;
	int		rd;
	int		x;
	int		y;

	map = open(argv[1], O_RDONLY);
	rd = read(map, &ch, 1);
	y = 0;
	while (rd > 0)
	{
		x = 0;
		while (ch != '\n')
		{
			data->map[y][x] = ch;
			x++;
			rd = read(map, &ch, 1);
		}
		y++;
		rd = read(map, &ch, 1);
	}
	close(map);
}

void	free_array(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(data->map[y]);
		y++;
	}
	free(data->map);
}

void	create_array(t_data *data, char **argv)
{
	malloc_array(data);
	write_in_array(data, argv);
}
