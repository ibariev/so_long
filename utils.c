#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	s -= len;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	while ((i < n) && (ptr1[i] != '\0' || ptr2[i] != '\0'))
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			res = (char *)(s + i);
			return (res);
		}
		i++;
	}
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	free_all(t_data *data)
{
	free_array(data);
	mlx_destroy_image(data->mlx->mlx, data->img_space);
	mlx_destroy_image(data->mlx->mlx, data->img_wall);
	mlx_destroy_image(data->mlx->mlx, data->img_clt);
	mlx_destroy_image(data->mlx->mlx, data->img_exit);
	mlx_destroy_image(data->mlx->mlx, data->img_rplayer);
	mlx_destroy_image(data->mlx->mlx, data->img_lplayer);
	free(data->mlx->mlx);
}
