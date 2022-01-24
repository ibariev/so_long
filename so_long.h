#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx_linux/mlx.h"

# define EMPTY_SPACE "Images/background.xpm"
# define WALL "Images/wall.xpm"
# define COLLECTIBLE "Images/collectible.xpm"
# define EXIT "Images/exit.xpm"
# define PLAYER_R "Images/player_right.xpm"
# define PLAYER_L "Images/player_left.xpm"

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_data
{
	void		*img_space;
	void		*img_wall;
	void		*img_clt;
	void		*img_exit;
	void		*img_rplayer;
	void		*img_lplayer;
	void		*img_lastpl;
	int			width;
	int			height;
	int			px;
	int			py;
	int			clt_ct;
	int			movement_ct;
	char		**map;
	t_mlx		*mlx;
}				t_data;

void	read_map(int argc, char **argv, t_data *data);
void	create_array(t_data *data, char **argv);
void	free_array(t_data *data);
void	parse_map(t_data *data);
void	create_initial_image(t_data *data, t_mlx *mlx);
void	process_events(t_data *data, t_mlx *mlx);
void	free_all(t_data *data);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);

#endif