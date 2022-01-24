#include "so_long.h"

void	exit_game(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->img_space, data->px * 32, data->py * 32);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->img_lastpl, data->px * 32 + x * 32, data->py * 32 + y * 32);
	data->movement_ct++;
	printf("The current number of movements = %d\n", data->movement_ct);
	printf("\n*****     The game is over    *****\n");
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	free_all(data);
	exit(EXIT_SUCCESS);
}

void	player_move(t_data *data, int x, int y)
{
	if (ft_strchr("0CP", data->map[data->py + y][data->px + x]))
	{
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->img_space, data->px * 32, data->py * 32);
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->img_space, data->px * 32 + x * 32, data->py * 32 + y * 32);
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->img_lastpl, data->px * 32 + x * 32, data->py * 32 + y * 32);
		if (data->map[data->py + y][data->px + x] == 'C')
		{
			data->clt_ct--;
			data->map[data->py + y][data->px + x] = '0';
		}
		data->px += x;
		data->py += y;
		data->movement_ct++;
		printf("The current number of movements = %d\n", data->movement_ct);
	}
	else if (data->map[data->py + y][data->px + x] == 'E' && data->clt_ct == 0)
		exit_game(data, x, y);
}

int	click_red_cross(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	printf("\n*****     The game is over    *****\n");
	free_all(data);
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 119)
		player_move(data, 0, -1);
	else if (keycode == 97)
	{
		data->img_lastpl = data->img_lplayer;
		player_move(data, -1, 0);
	}
	else if (keycode == 115)
		player_move(data, 0, 1);
	else if (keycode == 100)
	{
		data->img_lastpl = data->img_rplayer;
		player_move(data, 1, 0);
	}
	else if (keycode == 65307)
		click_red_cross(data);
	return (1);
}

void	process_events(t_data *data, t_mlx *mlx)
{
	data->mlx = mlx;
	data->movement_ct = 0;
	printf("\n*****    Start of the game    *****\n\n");
	mlx_key_hook(mlx->win, key_hook, data);
	mlx_hook(mlx->win, 17, 1L << 17, click_red_cross, data);
	mlx_loop(mlx->mlx);
}
