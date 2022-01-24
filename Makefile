NAME =		so_long

SRCS =		main.c			read_map.c					create_array.c\
			parse_map.c		create_initial_image.c		process_events.c\
			utils.c

OBJS =		$(SRCS:.c=.o)

RM =		rm -f

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

HEADER =	so_long.h

MLX_DIR =	mlx_linux

MLX_LIB =	-lmlx -lX11 -lXext -lm

all:		subsystem $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

subsystem:
			make -C $(MLX_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -L $(MLX_DIR) $(MLX_LIB) -o $@

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make clean -C $(MLX_DIR)

re:			fclean all

.PHONY:		all clean fclean re