#include "so_long.h"

void	put_background(t_data *data, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < 32 * data->height)
	{
		x = 0;
		while (x < 32 * data->width)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, data->img_space, x, y);
			x += 32;
		}
		y += 32;
	}
}

void	put_characters(t_data *data, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					data->img_wall, x * 32, y * 32);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					data->img_clt, x * 32, y * 32);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					data->img_exit, x * 32, y * 32);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					data->img_lastpl, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	create_initial_image(t_data *data, t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 32 * data->width,
			32 * data->height, "so_long");
	data->img_space = mlx_xpm_file_to_image(mlx->mlx, EMPTY_SPACE, &x, &y);
	data->img_wall = mlx_xpm_file_to_image(mlx->mlx, WALL, &x, &y);
	data->img_clt = mlx_xpm_file_to_image(mlx->mlx, COLLECTIBLE, &x, &y);
	data->img_exit = mlx_xpm_file_to_image(mlx->mlx, EXIT, &x, &y);
	data->img_rplayer = mlx_xpm_file_to_image(mlx->mlx, PLAYER_R, &x, &y);
	data->img_lplayer = mlx_xpm_file_to_image(mlx->mlx, PLAYER_L, &x, &y);
	data->img_lastpl = data->img_lplayer;
	put_background(data, mlx);
	put_characters(data, mlx);
}
