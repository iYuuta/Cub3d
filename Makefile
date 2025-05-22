NAME = cub3D

CC = cc
CFLAGS = -g -fsanitize=address
RM = rm -f

movements = movements/player_movement.c movements/tmp_map.c

rendering = rendering/rendering.c rendering/ray_casting.c

SRC_UTILS = utils/ft_putendl_fd.c utils/ft_strchr.c utils/ft_strdup.c \
            utils/ft_strjoin.c utils/ft_strlen.c utils/ft_substr.c \
            utils/get_next_line.c

SRC = $(SRC_UTILS) $(movements) $(rendering) main.c
OBJ = $(SRC:.c=.o)

MLX = mlx/libmlx_Linux.a
MLX_FLAGS = -L/usr/lib -lXext -lX11 -lm -lbsd

all: $(NAME)

$(MLX):
	make -C mlx

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c include/Cupid.h
	$(CC) $(CFLAGS) -I./include -c $< -o $@

bonus: all

clean:
	make -C mlx clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
