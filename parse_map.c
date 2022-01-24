#include "so_long.h"

void	error_map(t_data *data, int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == 1)
		ft_putstr_fd("Map is not surrounded by walls\n", 2);
	else if (error == 2)
		ft_putstr_fd("Invalid character in map\n", 2);
	else if (error == 3)
		ft_putstr_fd("The map must have at least 1 collectible\n", 2);
	else if (error == 4)
		ft_putstr_fd("The map must have 1 exit, not more, not less\n", 2);
	else if (error == 5)
		ft_putstr_fd("The map must have 1 player, not more, not less\n", 2);
	free_array(data);
	exit(EXIT_FAILURE);
}

void	check_walls(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= data->height - 1)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map[y][x] != '1')
				error_map(data, 1);
		}
		y += data->height - 1;
	}
	x = 0;
	while (x <= data->width - 1)
	{
		y = -1;
		while (++y < data->height)
		{
			if (data->map[y][x] != '1')
				error_map(data, 1);
		}
		x += data->width - 1;
	}
}

void	count_characters(t_data *data, int *exit_ct, int *player_ct)
{
	int	x;
	int	y;

	y = -1;
	data->clt_ct = 0;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (ft_strchr("01CEP", data->map[y][x]) == NULL)
				error_map(data, 2);
			if (data->map[y][x] == 'C')
				data->clt_ct++;
			else if (data->map[y][x] == 'E')
				(*exit_ct)++;
			else if (data->map[y][x] == 'P')
			{
				data->px = x;
				data->py = y;
				(*player_ct)++;
			}
		}
	}
}

void	check_characters(t_data *data)
{
	int	exit_ct;
	int	player_ct;

	exit_ct = 0;
	player_ct = 0;
	count_characters(data, &exit_ct, &player_ct);
	if (data->clt_ct < 1)
		error_map(data, 3);
	else if (exit_ct != 1)
		error_map(data, 4);
	else if (player_ct != 1)
		error_map(data, 5);
}

void	parse_map(t_data *data)
{
	check_characters(data);
	check_walls(data);
}
